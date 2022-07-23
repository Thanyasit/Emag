#B6022488 นายธัญสิทธิ์ อัครนราธิวัฒน์
import numpy as np # Import Math Lib
import matplotlib.pyplot as plt # Import Plot Lib
np.set_printoptions(precision=3) # ให้แสดงผลเป็นทศนิยม 3 ตำแหน่ง
#Robot Parameter
L1=15
L2=10
a0=0
b0=0
a=25-4.88
# Defind Path
# สมการวงกลม x=sqrt((10)**2-(y-10)**2)+10 
# เริ่มจาก y= 0 ไปถึง y=20
x1 = np.linspace(a, -a, 101)
print(x1)
y1 = np.sqrt((a)**2-(x1-a0)**2)+b0

x2 = np.linspace(-a, 0, 101)
y2 = -x2-a

x3= np.linspace(0, a, 101)
y3= x3-a

x=np.concatenate((x1,x2,x3),axis=None)
y=np.concatenate((y1,y2,y3),axis=None)
#tt = np.linspace(0,10,303)
tt = np.linspace(0,10,303)
print(x,'\n',y)
# Inverse Kinematic
def qq2(x,y):
    cq2=(x**2+y**2-L1**2-L2**2)/(2*L1*L2)
    sq2=np.sqrt(1-cq2**2)
    qq2 = np.arctan2(sq2,cq2)
    return qq2
q2 = qq2(x,y)
def qq1(x,y,q2):
    k1 = L1+L2*np.cos(q2)
    k2 = L2*np.sin(q2)
    qq1=np.arctan2(y,x)-np.arctan2(k2,k1)
    return qq1
q1 = qq1(x,y,q2)
#
#for i in range(101):
#    if np.sqrt(q1[i]**2)<0.00005:
#        q1[i]=0.0
#
print(q1*180/np.pi,'\n',q2*180/np.pi)        
# Plot q1 & q2 with time
fig1 = plt.figure()
ax1 = fig1.add_subplot(211)
ax1.plot(tt,q1*180/np.pi)
ax2 = fig1.add_subplot(212)
ax2.plot(tt,q2*180/np.pi)
plt.show(block=False)
# Forward kinematic
xx=L1*np.cos(q1)+L2*np.cos(q1+q2)
yy=L1*np.sin(q1)+L2*np.sin(q1+q2)

fig2=plt.figure()
plt.plot(xx,yy)
plt.axis('equal')
plt.show()
