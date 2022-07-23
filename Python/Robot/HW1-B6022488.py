import numpy as np
np.set_printoptions(precision=2, suppress=True)
y=np.radians(45)
print("rotation of 45 about y-axis")
z=np.radians(120)
print("rotation of 120 about z-axis")
x=np.radians(90)
print("rotation of 90 about x-axis")
A=np.mat([[1, 0, 0],
         [0, np.cos(x), -np.sin(x)],
         [0, np.sin(x), np.cos(x)]])
B=np.mat([[np.cos(z), -np.sin(z), 0],
         [np.sin(z), np.cos(z), 0],
         [0, 0, 1]])
C=np.mat([[np.cos(y), 0, np.sin(y)],
         [0, 1, 0],
         [-np.sin(y), 0, np.cos(y)]])
R2=A*B*C
print("Rotation matrix(R2) = ")
print(R2)
E=np.mat([0,0,0])
T2=np.vstack((R2,E))#เพิ่มแนวนอนล่าง
print(T2)
D2=np.transpose(np.mat([1,-2,4,1]))
T2=np.hstack((T2,D2))#เพิ่มด้านขวา
print("Transformation matrix(T2) = ")
print(T2)
P2=np.transpose(np.mat([12,-2,6,1]))
P=T2*P2
print("Position vector(P) = ")
print(P)
