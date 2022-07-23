#B6022488
#Transformation Matrix
import numpy as np
np.set_printoptions(precision=3, suppress=True)# Set printing decimal point
#Define Transformation Matrix Function
def T(a,alph,d,q):
    T = np.matrix([[np.cos(q),-np.sin(q)*np.cos(alph), np.sin(q)*np.sin(alph), a*np.cos(q)],
                   [np.sin(q), np.cos(q)*np.cos(alph),-np.cos(q)*np.sin(alph), a*np.sin(q)],
                   [0, np.sin(alph), np.cos(alph), d],
                   [0,0,0,1]])
    return T
def R(x):
    R=np.radians(x)
    return R
#  For 2R Planar Robot
#  D-H Parameters
a1, alph1, d1 = 0,0,0
a2, alph2, seta2 = 0,R(90),R(90)
a3, alph3, seta3 = 0,0,0
T10=(T(0,0,0,0))
# ###########################################1
# Variable
q1 = 0
q2 = 20
q3 = 20
# Link to Link Transformation Matrix
T32 = T(a3,alph3,q3,seta3)
T21 = T(a2,alph2,q2,seta2)
T10 = T(a1,alph1,d1,R(q1))
# Overall Transformation Matrix
T30 = T10*T21*T32
print('1.T30 =\n',T30)
# Position of Tool Point
D30 = T30[:3,-1]
print('Position of Tool Point is \n',D30,'\n')
############################################# 2
# Variable
q1 = 30
q2 = 28
q3 = 32
# Link to Link Transformation Matrix
T32 = T(a3,alph3,q3,seta3)
T21 = T(a2,alph2,q2,seta2)
T10 = T(a1,alph1,d1,R(q1))
# Overall Transformation Matrix
T30 = T10*T21*T32
print('2.T30 =\n',T30)
# Position of Tool Point
D30 = T30[:3,-1]
print('Position of Tool Point is \n',D30,'\n')
############################################# 3
# Variable
q1 = 30
q2 = 30
q3 = 20
# Link to Link Transformation Matrix
T32 = T(a3,alph3,q3,seta3)
T21 = T(a2,alph2,q2,seta2)
T10 = T(a1,alph1,d1,R(q1))
# Overall Transformation Matrix
T30 = T10*T21*T32
print('3.T30 =\n',T30)
# Angle between
print('Angle between X3 with Y0 =','%.2f'%np.rad2deg(np.arccos(T30[1,0]))," Degrees\n")
############################################# 4
# Variable
q1 = 45
q2 = 30
q3 = 28
# Link to Link Transformation Matrix
T32 = T(a3,alph3,q3,seta3)
T21 = T(a2,alph2,q2,seta2)
# Overall Transformation Matrix
T31 = T21*T32
print('4.T31 =\n',T31)
# Angle between
print('Angle between X3 with Y1 =','%.2f'%np.rad2deg(np.arccos(T31[1,0]))," Degrees\n")

