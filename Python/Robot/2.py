#B6022488 
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import style

pi = np.pi
np.set_printoptions(precision=3 ,suppress=True)
L1 = 10
L2 = 10
L3 = 13
#D-H Parameters
a1,alpha1,d1,q1=L1,0,0,10
a2,alpha2,d2,q2=L2,0,0,10
a3,alpha3,d3,q3=L3,0,0,15
a4,alpha4,d4,q4=0,0,0,0

def T(a,alph,d,q):
    T = np.matrix([[np.cos(q),-np.sin(q)*np.cos(alph), np.sin(q)*np.sin(alph), a*np.cos(q)],
                   [np.sin(q), np.cos(q)*np.cos(alph),-np.cos(q)*np.sin(alph), a*np.sin(q)],
                   [0, np.sin(alph), np.cos(alph), d],
                   [0,0,0,1]])
    return T
#Tranformation Matrix
T43=T(a4,alpha4,d4,q4*pi/180)
T32=T(a3,alpha3,d3,q3*pi/180)
T21=T(a2,alpha2,d2,q2*pi/180)
T10=T(a1,alpha1,d1,q1*pi/180)
T40=T10*T21*T32*T43
print(T40)
#tool point
print('X = ',T40[0,3])
print('X = ',T40[1,3])
print('X = ',T40[2,3])
