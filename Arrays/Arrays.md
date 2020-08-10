# Array
Is the array sorted or partially sorted? If it is, some form of binary search 
should be possible. This also usually means that the interview is looking for a
solutiuon faster than O(N). 

Can you sort the array? Sometimes sorting the array first may significantly 
simplify the problem. Make sure that the order of array elements do not need to 
be preserved before attempting a sort. 

For questions where summation or multiplication of a subarray is involved, 
pre-computation using hashing or a prefix/suffix sum/product may be useful. 

The following are the Worst Case complexity operations:
```
Space: O(N)
Lookup: O(1)
Append: O(1) 
Insert: O(N)
Delete: O(N) 
```

### <ins>Strengths</ins>
* Fast Lookups. Retrieving the element at a given index takes O(1) time, regardless
 of the length of the array. 
* Fast appens. Adding a new element at the end of the array takes O(1) time. 
### <ins>Weaknesses</ins>
* Fixed size. You need to specify how many elements you're going to store in your 
array ahead of time, unless using a vector. 
* Costly inserts and deletes. In the case of static arrays, you have to "scooot over" the 
the other elements to fill in or close gaps, which takes worst case O(N) time.  

