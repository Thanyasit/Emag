#B6022488 
import numpy as np
np.set_printoptions(precision=3)
def Rx(x):
    Rx = np.matrix([[1,0,0],
                  [0,np.cos(x),-np.sin(x)],
                  [0,np.sin(x),np.cos(x)]])
    return Rx
def Ry(x):
    Ry = np.matrix([[np.cos(x),0,np.sin(x)],
                  [0,1,0],
                  [-np.sin(x),0,np.cos(x)]])
    return Ry
def Rz(x):
    Rz = np.matrix([[np.cos(x),-np.sin(x),0],
                  [np.sin(x),np.cos(x),0],
                  [0,0,1]])
    return Rz
def R(x):
    R=np.radians(x)
    return R
x = 30
y = 60
z = 45
print('1. R =\n',Rx(R(x))*Ry(R(y))*Rz(R(z)))
print('2. R =\n',Ry(R(x))*Rz(R(y))*Ry(R(z)))
print('3. R =\n',Rx(R(x))*Ry(R(y))*Rz(R(z))*Ry(R(y))*Rx(R(x))*Rz(R(z)))
