#B6022488 
import numpy as np
np.set_printoptions(precision=3, suppress=True)
def T(x,y,a,d):
    T=np.matrix([[np.cos(x),-np.sin(x)*np.cos(y),np.sin(x)*np.sin(y),a*np.cos(x)],
               [np.sin(x),np.cos(x)*np.cos(y),-np.cos(x)*np.sin(y),a*np.sin(x)],
               [0,np.sin(y),np.cos(y),d],
               [0,0,0,1]])
    return T
x=np.radians(90)
T03=T(0,x,0,0)*T(0,0,20,0)*T(0,0,30,0)
print('T03(0) = \n',T03)
print('(a)x(0) =',T03[0,3])
print('(a)y(0) =',T03[1,3])
print('(a)z(0) =',T03[2,3])
x=np.radians(30)
y=np.radians(45)
z=np.radians(90)
T03=T(x,z,0,0)*T(x,0,20,0)*T(y,0,30,0)
print('T03 = \n',T03)
print('(b)x =','%.3f'%T03[0,3])
print('(b)y =','%.3f'%T03[1,3])
print('(b)z =','%.3f'%T03[2,3])
