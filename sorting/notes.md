# Selection Sort
* Select minimum and swap.
* Use when swaps are expensive
* TC: O(n^2) [worst,average,best]

# Bubble Sort 
* Push the max to the last by adjacent swaps.
* Use when Educational / very small data.
* TC: O(n^2) [worst]; O(n) [best]

# Insertion Sort
* Take an element and place it at its correct position.
* Use when Nearly sorted or small arrays
* TC: O(n^2) [average,worst]; O(n) [best]

# Shell Sort
* take a gap and use insertion sort for the gap elements.
* Use when Medium-size datasets.
* Types of shell sort
    1. Basic Shell Sort (gap = n/2, n/4, …, 1)
       Large gaps don’t reduce disorder efficiently → behaves close to insertion sort.
       | Case    | Complexity            |
       | ------- | --------------------- |
       | Best    | **O(n log n)** (rare) |
       | Average | **O(n²)**             |
       | Worst   | **O(n²)**             |

    2. Knuth Gap Sequence (1, 4, 13, 40, ...)
       Much faster in practice
       | Case    | Complexity               |
       | ------- | ------------------------ |
       | Best    | **O(n log n)**           |
       | Average | **O(n^(3/2)) ≈ O(n¹·⁵)** |
       | Worst   | **O(n^(3/2))**           |

    3. Ciura Gap Sequence (701, 301, 132, 57, 23, 10, 4, 1)
       Fastest real-world Shell Sort
       | Case    | Complexity                             |
       | ------- | -------------------------------------- |
       | Best    | **O(n log n)**                         |
       | Average | **~O(n¹·²⁵)**                          |
       | Worst   | **~O(n¹·³)** (not proven but observed) |

* Always use Knuth or Ciura
    | Gap Method | Avg Time  | Practical Speed |
    | ---------- | --------- | --------------- |
    | n/2        | O(n²)     | ❌ Slow          |
    | Knuth      | O(n¹·⁵)   | ✅ Good          |
    | Ciura      | ~O(n¹·²⁵) | 🚀 Excellent    |



# Count Sort
* Non comparison based
* Use when Small integer range


# Radix Sort 
* Use when Large integers, fixed digits.


# Bucket Sort
* Stable, Not In-place
* Use when Uniform distribution.
* Faster than comparison sorts for uniform data
* Works well with parallel processing
* TC: O(n) [average,worst] O(n^2) [worst]



| Algorithm      | Time Complexity (Best / Avg / Worst) | Space Complexity |
| -------------- | ------------------------------------ | ---------------- |
| Merge Sort     | O(n log n) / O(n log n) / O(n log n) | O(n)             |
| Quick Sort     | O(n log n) / O(n log n) / O(n²)      | O(log n)         |
| Selection Sort | O(n²) / O(n²) / O(n²)                | O(1)             |
| Insertion Sort | O(n) / O(n²) / O(n²)                 | O(1)             |
| Bubble Sort    | O(n) / O(n²) / O(n²)                 | O(1)             |
| Shell Sort     | O(n log n)* / ~O(n^1.5) / O(n²)      | O(1)             |
| Counting Sort  | O(n + k) / O(n + k) / O(n + k)       | O(k)             |
| Bucket Sort    | O(n) / O(n) / O(n²)                  | O(n + k)         |
| Radix Sort     | O(nk) / O(nk) / O(nk)                | O(n + k)         |



| Merge Sort     | Large datasets, linked lists, guaranteed performance |
| Quick Sort     | Fast general-purpose |

# Stable - Merge, Insertion, Bubble, Counting, Bucket, Radix
# Not Stable - Quick, Selection, Shell

# In-Place - Quick, Selection, Insertion, Bubble, Shell
# Not In-Place - Merge, Counting, Bucket, Radix

# Counting Bucket and Radix are not comparison based.