#!/usr/bin/env python
# coding: utf-8

# In[10]:


x_previous=-3
lr=0.001
max_iters=0
i=0
def J(x):
    return x**2-(4*x)
def dJ(x):
    return 2*x-4
while(max_iters==0):
    x_new=x_previous-lr*dJ(x_previous)
    x_previous=x_new
    i=i+1;
    if(x_new>0):
        if(x_new<0.01):
            max_iters=1 
    print('Iteration: {}, x_new = {}'.format(i,x_new))


# In[ ]:




