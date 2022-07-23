#นายธัญสิทธิ์ อัครนราธิวัฒน์
#B6022488
import numpy as np
np.set_printoptions(precision=2, suppress=True)
import matplotlib.pyplot as plt
L1=10
L2=10
r=10
a=10
b=0
x=np.linspace(20,10,11)
y=-x+20
#print(y)
def q2(x,y):
    cq2=(x**2+y**2-L1**2-L2**2)/(2*L1*L2)
    sq2=np.sqrt(1-cq2**2)
    q2=np.arctan2(sq2,cq2)
    return q2
print('q2 =')
print(q2(x,y)*180/np.pi)
def q1(x,y,q2):
    k1=L1+L2*np.cos(q2(x,y))
    k2=L2*np.sin(q2(x,y))
    q1=np.arctan2(y,x)-np.arctan2(k2,k1)
    return q1
print('q1 =')
print(q1(x,y,q2)*180/np.pi)
q1 = q1(x,y,q2)
q2 = q2(x,y)
#print(q1,'\n','\n',q2)
p=L1*np.cos(q1)+L2*np.cos(q1+q2)
s=L1*np.sin(q1)+L2*np.sin(q1+q2)
plt.xlabel('x')
plt.ylabel('y')
plt.title('Linear')
plt.plot(p,s)
plt.show()
