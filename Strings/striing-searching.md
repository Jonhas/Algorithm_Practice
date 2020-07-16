# String-searching Algorithms
In computer Science, string-searching algorithms, sometimes called string-matching algorithms, 
are an important class of string algorithms that try to find a place where one of several patterns 
are found within a larger string or text. A basic example of string searching is when the pattern and 
the searched text are arrays of elements of an alphabet (finite set) $\Sigma$. 

## Kinds of Searching
The most basic case of string searching involves one(often very long) string, sometimes called the haystack, and 
one(often very short) string, sometimes called the needle. The goal is to find one or more occurences of the needle 
within the haystack. Very commonly, however, various constraints are added. 


The input is an array of characters, referred to as the haystack, which is the string we are searching for. The second input is an array of characters, called the needle, which is the string we are searching for. We do not even know if the string is contained in the haystack, neither where it could be found. Output is in the index where needle can be found within the haystack. 


For example, one might search for 'to' within the following string:
``` 
Some books are to be tasted, others to be swalloed, and some few to be chewed and digested. 
```


In the .cpp file within this directory, we will showing four different string searching algorithms: brute force, Knuth-Morris-Pratt, Boyer-Moore, and Rabin-Karp. 