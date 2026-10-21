# Case Study 1: E-commerce Product Sorting Using Divide and Conquer

**Student Name:** ____________________  
**Branch:** Computer Engineering  
**Subject:** Data Structures  
**Unit:** 1  
**College:** ____________________

## 1. Aim
To sort e-commerce products by price using the Merge Sort algorithm and understand the Divide and Conquer strategy.

## 2. Introduction
Online shopping websites show many products with different prices. Sorting products by price helps users compare items and find cheaper or more expensive products easily. Merge Sort is a sorting algorithm that uses the Divide and Conquer method.

## 3. Problem Statement
Create a Python program that sorts a list of products from lowest price to highest price using Merge Sort.

## 4. Strategy Used: Divide and Conquer
The problem is divided into smaller parts, each part is sorted, and then the sorted parts are combined.

- **Divide:** Split the product list into two halves.
- **Conquer:** Sort each half recursively.
- **Combine:** Merge the two sorted halves into one sorted list.

## 5. Algorithm
1. If the list contains zero or one item, return it as it is.
2. Divide the list into two halves.
3. Apply Merge Sort to both halves.
4. Merge the halves in ascending order of price.
5. Display the sorted products.

## 6. Example
Input products:

| Product | Price (₹) |
|---|---:|
| Headphones | 1200 |
| Keyboard | 850 |
| Mouse | 450 |
| Monitor | 7500 |
| USB Cable | 200 |

After sorting by price:

| Product | Price (₹) |
|---|---:|
| USB Cable | 200 |
| Mouse | 450 |
| Keyboard | 850 |
| Headphones | 1200 |
| Monitor | 7500 |

## 7. Python Program
The file `ecommerce_product_sorting.py` contains the complete program.

## 8. How to Run
```bash
python ecommerce_product_sorting.py
```

## 9. Time and Space Complexity
- **Best, average and worst time:** `O(n log n)`
- **Extra space:** `O(n)` for the temporary lists used during merging.

Here, `n` is the number of products.

## 10. Advantages
- Works well for large lists.
- Gives predictable `O(n log n)` time complexity.
- The method is easy to explain by dividing a list into smaller lists.

## 11. Conclusion
In this case study, I used Merge Sort to arrange products by price. It showed how Divide and Conquer breaks a large problem into smaller problems and combines their results.
