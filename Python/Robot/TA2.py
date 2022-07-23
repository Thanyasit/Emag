import numpy as np
A=np.mat([[0, -1/np.sqrt(2), 1/np.sqrt(2)],
          [1,0,0],
          [0,1/np.sqrt(2),1/np.sqrt(2)]])
B=np.mat([[1, 0, 0],
          [1,np.sqrt(3)/2,-1/2],
          [0,1/2,np.sqrt(3)/2]])
AB= A*B

AAT=A*np.transpose(A)

C = np.linalg.inv(A) - np.transpose(A)
print("A dot B =",AB)
print("A * AT =")
print(AAT)
print("A-1 - AT =",C)
print(C)
