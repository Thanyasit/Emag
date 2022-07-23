import numpy as np # Import Math Lib

import matplotlib.pyplot as plt # Import Plot Lib

np.set_printoptions(precision=3) # ให้แสดงผลเป็นทศนิยม 3 ตำแหน่ง

#Robot Parameter
L1 =15
L2=10

# Defind Path
# สมการเส้นตรงคือ y=-x+L1+L2
# เริ่มจาก x= L1+L2 ไปถึง x=L1

x = np.linspace(L1+L2, L1, 101)
y = -x+L1+L2
tt = np.linspace(0,10,101)


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

for i in range(101):
    if np.sqrt(q1[i]**2)<0.00005:
        q1[i]=0.0
#

print(q1*180/np.pi,'\n',q2*180/np.pi)        

# Plot q1 & q2 with time

fig = plt.figure()

ax1 = fig.add_subplot(311)
ax1.plot(tt,q1*180/np.pi)

ax2 = fig.add_subplot(312)
ax2.plot(tt,q2*180/np.pi)

# Forward kinematic
xx=L1*np.cos(q1)+L2*np.cos(q1+q2)
yy=L1*np.sin(q1)+L2*np.sin(q1+q2)

ax3 = fig.add_subplot(313)
ax3.plot(xx,yy)
ax3.axis('equal')
plt.show()


