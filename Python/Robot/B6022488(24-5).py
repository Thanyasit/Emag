import numpy as np
np.set_printoptions(precision=2, suppress=True)
l1=0
l2=20
l3=15
a1=l1
a2=l2
a3=l3
alpha1=(np.pi/2)
alpha2=0
alpha3=0
d1=0
d2=0
d3=0
r11=0.612
r12=-0.354
r13=0.707
r14=22.846
r21=0.612
r22=-0.354
r23=-0.707
r24=22.846
r31=0.5
r32=0.866
r33=0
r34=12.676
q1=np.arctan2(r24,r14)
q2=np.arctan2((-l3*r31)+r34,+np.sqrt(((-l3*r11)+r14)**2+(-l3*r21+r24)**2))
q2n=np.arctan2((-l3*r31)+r34,-(np.sqrt(((-l3*r11)+r14)**2+(-l3*r21+r24)**2)))
q3=(np.arctan2(r31,r32))-q2
q3n=np.arctan2(r31,r32)-q2n
print('q1 =','%.2f'%(q1*180/np.pi)," Degrees")
print('q2 =','%.2f'%(q2*180/np.pi)," Degrees")
print('q2n =','%.2f'%(q2n*180/np.pi)," Degrees")
print('q3 =','%.2f'%(q3*180/np.pi)," Degrees")
print('q3n =','%.2f'%(q3n*180/np.pi)," Degrees")
###
###r11=np.cos(q1)*np.cos(q1+q2)
###r12=-np.cos(q1)*np.sin(q2+q3)
###r13=np.sin(q1)
###r14=np.cos(q1+((l3*np.cos(q2+q3))+(l2*np.cos(q2))))
###r21=np.sin(q1)+np.cos(q2+q3)
###r22=-np.sin(q1)*np.sin(q2+q3)
###r23=-np.cos(q1)
###r24=np.sin(q1+
###r31=0.5
###r32=0.866
###r33=0
###r34=12.676
x=np.cos(q1)*((l3*np.cos(q2+q3))+(l2*np.cos(q2)))
print('Forward Negative Solution x,y =',x)

