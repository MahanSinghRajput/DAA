# Selection Sort
* Select minimum and swap.
* TC: O(n^2) [worst,average,best]

# Bubble Sort 
* Push the max to the last by adjacent swaps.
* TC: O(n^2) [worst]; O(n) [best]

# Insertion Sort
* Take an element and place it at its correct position.
* TC: O(n^2) [average,worst]; O(n) [best]

# Shell Sort
* take a gap and use insertion sort for the gap elements.
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
* Good for small numbers
