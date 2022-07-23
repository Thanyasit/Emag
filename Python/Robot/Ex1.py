#B6022488 
import numpy as np
np.set_printoptions(precision=3)
def T(x,y,a,d):
    T=np.matrix([[np.cos(x),-np.sin(x)*np.cos(y),np.sin(x)*np.sin(y),a*np.cos(x)],
               [np.sin(x),np.cos(x)*np.cos(y),-np.cos(x)*np.sin(y),a*np.sin(x)],
               [0,np.sin(y),np.cos(y),d],
               [0,0,0,1]])
    return T
print(T(0,0,15,0))
print(T(0,0,20,0))
T02=T(0,0,15,0)*T(0,0,20,0)
print('T02(0) = \n',T02)
print('x(0) =',T02[0,3])
print('y(0) =',T02[1,3])
print('z(0) =',T02[2,3])
x=np.radians(30)
####
y=np.radians(15);
###
T02=T(x,0,15,0)*T(y,0,20,0)
print('T02(30) = \n',T02)
print('x(30) =','%.3f'%T02[0,3])
print('y(30) =','%.3f'%T02[1,3])
print('z(30) =','%.3f'%T02[2,3])

