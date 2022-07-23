import numpy as np
import matplotlib.pyplot as plt
from matplotlib import style

pi = np.pi
np.set_printoptions(precision=3 ,suppress=True)
L1 = 5
L2 = 10
L3 = 15
#D-H Parameters
a1,alpha1,d1,q1=L1,pi/2,0,0
a2,alpha2,d2,q2=L2,0,0,0
a3,alpha3,d3,q3=L3,0,0,0

def T(a,alph,d,q):
    T = np.matrix([[np.cos(q),-np.sin(q)*np.cos(alph), np.sin(q)*np.sin(alph), a*np.cos(q)],
                   [np.sin(q), np.cos(q)*np.cos(alph),-np.cos(q)*np.sin(alph), a*np.sin(q)],
                   [0, np.sin(alph), np.cos(alph), d],
                   [0,0,0,1]])
    return T
T32=T(a3,alpha3,d3,q3)
T21=T(a2,alpha2,d2,q2)
T10=T(a1,alpha1,d1,q1)
T30=T10*T21*T32
print(T30)
