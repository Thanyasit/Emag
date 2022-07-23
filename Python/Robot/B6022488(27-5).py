#B6022488 นายธัญสิทธิ์ อัครนราธิวัฒน์
import numpy as np
np.set_printoptions(precision=2, suppress=True)
a1=L11=15
a2=L2=18
a3=0
a4=0
ahlpa1=0
ahlpa2=0
ahlpa3=np.pi
ahlpa4=0
d1=L12=4
d2=0
d3=3
d4=L4=5
s1=s2=np.deg2rad(15)
s4=np.deg2rad(45)
#overall transformation matrix
T40=np.mat([[np.cos(s1+s2-s4),np.sin(s1+s2-s4),0,L2*np.cos(s1+s2)+L11*np.cos(s1)],
        [np.sin(s1+s2-s4),-np.cos(s1+s2-s4),0,L2*np.sin(s1+s2)+L11*np.sin(s1)],
        [0,0,-1,L12+d3-L4],
        [0,0,0,1]])
print("1.overall transformation matrix =")
print(T40)
#Recheck Positive
print(" Recheck Positive")
d3=T40[2,3]+L4-L12
cs2=(T40[0,3]**2+T40[1,3]**2-L11**2-L2**2)/(2*L11*L2)
s2=np.arctan2(np.sqrt(1-cs2**2),cs2)
r=np.sqrt((L11+L2*np.cos(s2))**2+(L2*np.sin(s2)**2))
py=np.arctan2((L2*np.sin(s2))/r,(L11+L2*np.cos(s2))/r)
s1=np.arctan2((T40[1,3])/r,(T40[0,3])/r)-py
s4=s2+s1-np.arctan2(T40[1,0],T40[0,0])
print('  s2 =','%.2f'%(s2*180/np.pi)," Degrees")
print('  s1 =','%.2f'%(s1*180/np.pi)," Degrees")
print('  d3 =',d3," cm")
print('  s4 =','%.2f'%(s4*180/np.pi)," Degrees")
#Recheck Negative
print(" Recheck Negative")
d3=T40[2,3]+L4-L12
cs2=(T40[0,3]**2+T40[1,3]**2-L11**2-L2**2)/(2*L11*L2)
s2n=np.arctan2(-np.sqrt(1-cs2**2),cs2)
r=np.sqrt((L11+L2*np.cos(s2n))**2+(L2*np.sin(s2n)**2))
py=np.arctan2((L2*np.sin(s2n))/r,(L11+L2*np.cos(s2n))/r)
s1n=np.arctan2(T40[1,3]/r,T40[0,3]/r)-py
s4n=s1n+s2n-np.arctan2(T40[1,0],T40[0,0])
print('  s2n =','%.2f'%(s2n*180/np.pi)," Degrees")
print('  s1n =','%.2f'%(s1n*180/np.pi)," Degrees")
print('  d3n =',d3," cm")
print('  s4n =','%.2f'%(s4n*180/np.pi)," Degrees")
#joint displacement
T40=np.mat([[0.878,-0.479,0,30.077],
            [-0.479,-0.878,0,12.882],
            [0,0,-1,2],
            [0,0,0,1]])
#Positive
print("2. joint displacement(Positive) =")
d3=T40[2,3]+L4-L12
cs2=(T40[0,3]**2+T40[1,3]**2-L11**2-L2**2)/(2*L11*L2)
s2=np.arctan2(np.sqrt(1-cs2**2),cs2)
r=np.sqrt((L11+L2*np.cos(s2))**2+(L2*np.sin(s2)**2))
py=np.arctan2((L2*np.sin(s2))/r,(L11+L2*np.cos(s2))/r)
s1=np.arctan2(T40[1,3]/r,T40[0,3]/r)-py
s4=s1+s2-np.arctan2(T40[1,0],T40[0,0])
print('  s2 =','%.2f'%(s2*180/np.pi)," Degrees")
print('  s1 =','%.2f'%(s1*180/np.pi)," Degrees")
print('  d3 =',d3," cm")
print('  s4 =','%.2f'%(s4*180/np.pi)," Degrees")
#Negative
print("   joint displacement(Negative) =")
d3=T40[2,3]+L4-L12
cs2=(T40[0,3]**2+T40[1,3]**2-L11**2-L2**2)/(2*L11*L2)
s2n=np.arctan2(-np.sqrt(1-cs2**2),cs2)
r=np.sqrt((L11+L2*np.cos(s2n))**2+(L2*np.sin(s2n)**2))
py=np.arctan2((L2*np.sin(s2n))/r,(L11+L2*np.cos(s2n))/r)
s1n=np.arctan2(T40[1,3]/r,T40[0,3]/r)-py
s4n=s1n+s2n-np.arctan2(T40[1,0],T40[0,0])
print('  s2n =','%.2f'%(s2n*180/np.pi)," Degrees")
print('  s1n =','%.2f'%(s1n*180/np.pi)," Degrees")
print('  d3n =',d3," cm")
print('  s4n =','%.2f'%(s4n*180/np.pi)," Degrees")
#Recheck overall transformation matrix (Positive)
T40=np.mat([[np.cos(s1+s2-s4),np.sin(s1+s2-s4),0,L2*np.cos(s1+s2)+L11*np.cos(s1)],
        [np.sin(s1+s2-s4),-np.cos(s1+s2-s4),0,L2*np.sin(s1+s2)+L11*np.sin(s1)],
        [0,0,-1,L12+d3-L4],
        [0,0,0,1]])
print(" Recheck overall transformation matrix (Positive)=")
print(T40)
#Recheck overall transformation matrix (Negative)
T40=np.mat([[np.cos(s1n+s2n-s4n),np.sin(s1n+s2n-s4n),0,L2*np.cos(s1n+s2n)+L11*np.cos(s1n)],
        [np.sin(s1n+s2n-s4n),-np.cos(s1n+s2n-s4n),0,L2*np.sin(s1n+s2n)+L11*np.sin(s1n)],
        [0,0,-1,L12+d3-L4],
        [0,0,0,1]])
print(" Recheck overall transformation matrix (Negative)=")
print(T40)
