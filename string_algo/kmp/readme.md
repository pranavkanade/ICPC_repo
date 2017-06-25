## KMP Algorithm

### Pattern Pre Processing

* We will have a __pattern__ given to search in the given string.

* Create an array to hold the result of __Preprocessing__.

* This preprocessing takes advantage of matching of suffix and prefix of
the given pattern.

* So, 0th index of the array will be '0'.

* Temp variable '__j__' = 0 and '__i__' = 1, where __j__ is for calculating
matching and __i__ is to iterate through given pattern.

* Now, looping for __i__ through the length of the pattern -
       we match the __char__ at __i__ and __j__
       if match found increment __j__,
       else if __j__ > 0 then -
       __j__ = __f[j-1]__
       __i--__



### Match Pattern

* Now as we have a pre-processed array and pattern

* initialize two pointers at the start of the strings,
and compare character by character.

* once mismatch is found restore the pointer of pattern to the value of index in preprocessed array

* and continue checking if not again perform the previous step