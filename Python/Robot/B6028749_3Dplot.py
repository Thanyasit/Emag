import numpy as np
import matplotlib.pyplot as plt
from matplotlib import style

pi = np.pi
np.set_printoptions(precision=3 ,suppress=True)
#defined
L1 = 5
L2 = 30
L3 = 30
L5 = 10

#  D-H Parameters
a1, alph1, d1 = 0, -90, L1
a2, alph2, d2 = L2, 0, 0
a3, alph3, d3 = L3, 0, 0
a4, alph4, d4 = 0, -90, 0
a5, alph5, d5 = 0, 0, L5
q1 = np.linspace(0,30,11)
q2 = np.linspace(0,15,11)
print(q2)
q3 = np.linspace(0,15,11)
q4 = np.linspace(0,30,11)
q5 = np.linspace(0,45,11)

def T(a,alph,d,q):
    T = np.matrix([[np.cos(q),-np.sin(q)*np.cos(alph), np.sin(q)*np.sin(alph), a*np.cos(q)],
                   [np.sin(q), np.cos(q)*np.cos(alph),-np.cos(q)*np.sin(alph), a*np.sin(q)],
                   [0, np.sin(alph), np.cos(alph), d],
                   [0,0,0,1]])
    return T

#Tranformation Matrix
#print(q2*pi/180)
T54 = T(a5,alph5,d5,q5*pi/180)
T43 = T(a4,alph4*pi/180,d4,(q4*pi/180)-(pi/2))
#print(T43)
T32 = T(a3,alph3,d3,q3*pi/180)
T21 = T(a2,alph2,d2,q2*pi/180)
T10 = T(a1,alph1*pi/180,d1,q1*pi/180)
T50 = T10*T21*T32*T43*T54
#print(T50)
D50 = T50[:3,-1]
#print(D50)

#plot 3D
style.use('ggplot')
fig = plt.figure()
ax = fig.add_subplot(211,projection='3d')
x = np.transpose(D50[0,0])
#print(x)
y = np.transpose(D50[1,0])
#print(y)
z = np.transpose(D50[2,0])
#print(z)
ax.plot_wireframe(x,y,z)
ax.set_title('Displacement')
ax.set_xlabel('x-axis')
ax.set_ylabel('y-axis')
ax.set_zlabel('z-axis')
ax1 = fig.add_subplot(212,projection='3d')
ax1.plot_wireframe(x,y,z)
plt.show()
