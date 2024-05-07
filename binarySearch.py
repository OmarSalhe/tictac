def binarySearch(sorted_arr, item, startBound, endBound):
    if (sorted_arr[endBound] == item): # item at the end
        return endBound

    if (startBound > endBound): # not in the array
        return -1

    middleIndex = (startBound + endBound) // 2

    if (item < sorted_arr[middleIndex]):
        return binarySearch(sorted_arr, item, startBound, middleIndex - 1) # go left
    elif (item > sorted_arr[middleIndex]):
        return binarySearch(sorted_arr, item, middleIndex + 1, endBound) # go right
    elif (item == sorted_arr[middleIndex]):
        return middleIndex

arr = [1, 2, 3, 4, 10, 12, 14, 21]
#      0  1  2  3   4   5   6   7

endOfArr = len(arr) - 1 # the length of the array
startOfArr = 0
print(binarySearch(arr, 1, startOfArr, endOfArr)) # beginning
print(binarySearch(arr, 21, startOfArr, endOfArr)) # end
print(binarySearch(arr, 10, startOfArr, endOfArr)) # middle
print(binarySearch(arr, 5, startOfArr, endOfArr)) # not there

# binary search
# 1. compare the middle of the array to the item
# 2. if less 
#   from same start to before middle
#   do binary search
#    if greater 
#   from after middle to same end
#   do binary search
#    if equal
#   return index of item
