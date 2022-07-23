#!/usr/bin/env python
# coding: utf-8

# In[90]:


import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
pd.read_csv("D:/Study/3-63/ML/2-1/SalaryData.csv").head()


# In[166]:


df=pd.read_csv("D:/Study/3-63/ML/2-1/SalaryData.csv")
#matrix=df.values
x1 = np.linspace(1.1,10.5,29)
x=df[['YearsExperience']]
y=df.Salary
print(x1)
#print(x)
#print(y)


# In[167]:


from sklearn.linear_model import LinearRegression

model = LinearRegression()
model 


# In[168]:


model.fit(x,y)


# In[169]:


model.score(x,y)


# In[170]:


model.intercept_


# In[171]:


model.coef_


# In[172]:


plt.scatter(x,y)


# In[173]:


y2=model.intercept_ + model.coef_*x1


# In[174]:


plt.scatter(x,y)
plt.plot(x1,y2,'r')
plt.xlabel('YearsExperience')
plt.ylabel('Salary')
#plt.show()


# In[ ]:




