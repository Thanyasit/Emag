import numpy as np
np.set_printoptions(precision=2, suppress=True)
j=np.mat([[0.866, -0.500, 0, 11],
         [0.5000, 0.866, 0, -1],
         [0, 0, 1, 8],
         [0, 0, 0, 1]])
k=np.mat([[1, 0, 0, 0],
         [1, 0.866, -0.500, 10],
         [0, 0.500, 0.866, -20],
         [0, 0, 0, 1]])
A=j*k
B=np.rad2deg(np.arccos(A[0,1]))
C=np.rad2deg(np.arccos(A[0,2]))
#D1=j[0,3]
#D2=j[1,3]
#D3=j[2,3]
