
# coding: utf-8

# In[12]:

import sys
import math as mat

class primeSieveEratosthenes:
    def __init__(self, lim):
        self.lim = lim
        
    # def of sieve
    def sieve(self):
        primes = []
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
                primes.append(i)
        return primes, len(primes)


primeSieve = primeSieveEratosthenes(100)
primes, length = primeSieve.sieve()
print(primes , length)


# In[ ]:



