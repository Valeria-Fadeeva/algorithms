import timeit
import math


def binary_search(arr, item):
    low = 0
    high = len(arr)-1

    while low <= high:
        mid = math.floor((low + high) / 2)
        value = arr[mid]

        if value == item:
            return mid

        elif value > item:
            high = mid - 1

        else:
            low = mid + 1

    return None


max_item_count = 1_000_000_000
arr = [i for i in range(max_item_count)]

item = 5

t1 = timeit.timeit('binary_search(arr, item)', number=1, globals=globals())
print(f'{t1}')
