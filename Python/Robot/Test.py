#B6022488 นายธัญสิทธิ์ อัครนราธิวัฒน์ (21-6)
import numpy as np # Import Math Lib

import matplotlib.pyplot as plt # Import Plot Lib

np.set_printoptions(precision=3, suppress=True) # ให้แสดงผลเป็นทศนิยม 3 ตำแหน่ง
L1 = 5
L2=L3=30
L5=10
s1=s2=s3=s5=0
s4=-np.pi/2
T10=np.mat([[np.cos(s1), 0, -np.sin(s1), 0],
         [np.sin(s1), 0, -np.cos(s1), 0],
         [0, -1, 0, L1],
         [0, 0, 0, 1]])
T21=np.mat([[np.cos(s2), -np.sin(s2), 0, L2*np.cos(s2)],
         [np.sin(s2), np.cos(s2), 0, L2*np.sin(s2)],
         [0, 0, 1, 0],
         [0, 0, 0, 1]])
T32=np.mat([[np.cos(s3), -np.sin(s3), 0, L3*np.cos(s3)],
         [np.sin(s3), np.cos(s3), 0, L3*np.sin(s3)],
         [0, 0, 1, 0],
         [0, 0, 0, 1]])
T43=np.mat([[np.cos(s4), 0, -np.sin(s4), 0],
         [np.sin(s4), 0, -np.cos(s4), 0],
         [0, -1, 0, 0],
         [0, 0, 0, 1]])
T54=np.mat([[np.cos(s5), -np.sin(s5), 0, 0],
         [np.sin(s5), np.cos(s5), 0, 0],
         [0, 0, 1, L5],
         [0, 0, 0, 1]])
T50=T10*T21*T32*T43*T54
print(T50)
