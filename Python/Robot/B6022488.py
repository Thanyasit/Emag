#B6022488 นายธัญสิทธิ์ อัครนราธิวัฒน์
import numpy as np
np.set_printoptions(precision=3)
x=27.133
y=21.642
l1=15
l2=20
cq2=((x**2)+(y*y)-(l1**2)-(l2**2))/(2*l1*l2)
sq2=np.sqrt(1-cq2**2)
q2=np.arctan2(sq2,cq2)
print('q2 =','%.2f'%(q2*180/np.pi)," Degrees")

k1=l1+l2*np.cos(q2)
k2=l2*np.sin(q2)
q1=np.arctan2(y,x)-np.arctan2(k2,k1)
print('q1 =','%.2f'%(q1*180/np.pi)," Degrees")
