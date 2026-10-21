# E-commerce Product Sorting using Merge Sort
# Divide and Conquer strategy

products = [
    ("Headphones", 1200),
    ("Keyboard", 850),
    ("Mouse", 450),
    ("Monitor", 7500),
    ("USB Cable", 200),
]


def merge_sort(items):
    if len(items) <= 1:
        return items

    middle = len(items) // 2
    left_half = merge_sort(items[:middle])
    right_half = merge_sort(items[middle:])

    return merge(left_half, right_half)


def merge(left, right):
    result = []
    i = 0
    j = 0

    while i < len(left) and j < len(right):
        if left[i][1] <= right[j][1]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    result.extend(left[i:])
    result.extend(right[j:])
    return result


print("Products before sorting:")
for name, price in products:
    print(f"{name}: Rs. {price}")

sorted_products = merge_sort(products)

print("\nProducts sorted by price (low to high):")
for name, price in sorted_products:
    print(f"{name}: Rs. {price}")
