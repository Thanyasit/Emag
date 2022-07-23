#B6022488 นายธัญสิทธิ์ อัครนราธิวัฒน์ (2)-21-6
import numpy as np # Import Math Lib
#from mpl_toolkits.mplot3d import axes3d
import matplotlib.pyplot as plt # Import Plot Lib
np.set_printoptions(precision=3, suppress=True) # ให้แสดงผลเป็นทศนิยม 3 ตำแหน่ง
L1 = 5
L2=L3=30
L5=10
x1=[0]
y1=[0]
z1=[0]
q1=q4=np.linspace(0, np.deg2rad(30), 11)
#print(q1)
q2=q3=np.linspace(0, np.deg2rad(15), 11)
q5=np.linspace(0, np.deg2rad(45), 11)
for x in range(11):
    s1=s4=q1[x]
    s2=s3=q2[x]
    s5=q5[x]
    T50=np.mat([[(np.cos(s1)*np.sin(s2+s3+s4)*np.cos(s5))+(np.sin(s1)*np.sin(s5)),
                 -(np.cos(s1)*np.sin(s2+s3+s4)*np.sin(s5))+(np.sin(s1)*np.cos(s5)),
                 np.cos(s1)*np.cos(s2+s3+s4),
                 np.cos(s1)*((L2*np.cos(s2))+(L3*np.cos(s2+s3))+(L5*np.cos(s2+s3+s4)))],
         [(np.sin(s1)*np.cos(s2+s3+s4)*np.cos(s5))-(np.cos(s1)*np.cos(s5))
          -(np.sin(s1)*np.sin(s2+s3+s4)*np.sin(s5))-(np.cos(s1)*np.cos(s5)),
          np.sin(s1)*np.cos(s2+s3+s4),
          np.sin(s1)*((L2*np.cos(s2))+(L3*np.cos(s2+s3))+(L5*np.cos(s2+s3+s4)))],
         [-np.cos(s2+s3+s4)*np.cos(s5),
          np.cos(s2+s3+s4)*np.sin(s5),
          -np.sin(s2+s3+s4),
          L1-L2*np.sin(s2)-L3*np.sin(s2+s3)-L5*np.sin(s2+s3+s4)],
         [0,0,0,1]])
    #x2=[T50[0,3]]
    print('T50',T50)
    #print(x2)
    #x1=x1+x2
    #print(x1)
    #y2=[T50[1,3]]
    #y1=y1+y2
    #z2=[T50[2,3]]
    #z1=z1+z2
#print(x1)
#x1.remove(0)
#y1.remove(0)
#z1.remove(0)
#print('x =\n',x1)
#print('y =\n',y1)
#print('z =\n',z1)
#fig = plt.figure()
#ax = plt.axes(projection='3d')
#ax.plot3D(x1,y1,z1,'blue')
#ax.set_xlabel('x')
#ax.set_ylabel('y')
#ax.set_zlabel('z')
#plt.show()

