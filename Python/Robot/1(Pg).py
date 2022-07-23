import numpy as np
a=np.mat([[0.866,-0.5,0,10],[0.5,0.866,0,5],[0,0,1,0],[0,0,0,1]])
b=np.mat([4,3,0,1])
c=np.transpose(b)
print(a*c)
a1=np.mat([[0.866,-0.5,0],[0.5,0.866,0],[0,0,1]])
b1=np.mat([4,3,0])
c1=np.transpose(b1)
print(a1*c1)
