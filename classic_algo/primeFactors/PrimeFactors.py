
# coding: utf-8

# In[28]:

import sys
import math as mat

class primeSieveEratosthenes:
    def __init__(self, lim):
        self.lim = lim
        self.primes = []
        self.factors = []
        self.factDict = {}
        
    # def of sieve
    def sieve(self):
        arr = [True for i in range(self.lim+1)]
        arr[0] = False
        arr[1] = False
        for i in range(2, int(mat.sqrt(self.lim))+1):
            if arr[i]:
                for l in range(2*i, self.lim+1, i):
                    arr[l] = False

        #print(arr)
        for i in range(len(arr)):
            if arr[i] :
                self.primes.append(i)
        return
    
    # factors
    def factorsPrime(self, num):
        self.sieve()
        for i in self.primes:
             while num % i == 0:
                self.factors.append(i)
                num = num/i
        return 
    
    # use of dictionary to store the unique factors with its count as its value
    def uniqueFactors(self, num):
        self.factorsPrime(num)
        for i in self.factors:
            self.factDict[i] = self.factDict.get(i, 0) + 1
        return
    
lim = int(input())
primeSieve = primeSieveEratosthenes(int(lim/2)+1)
primeSieve.uniqueFactors(lim)
print(primeSieve.factors)
print(primeSieve.factDict)


# In[16]:

d = {}
d[1] = 2


# In[17]:

d


# In[18]:

d[1]++


# In[20]:

d.get(1,0)++


# In[21]:

d[1] = d.get(1,0) + 1


# In[22]:

d[1]


# In[23]:

d[1] = d.get(1, 0)++


# In[24]:

lis = [2,3,4,2,2,4]
for i in lis:
    d[i] = d.get(i, 0) + 1


# In[25]:

d


# In[ ]:



