def findChange(lst01):
    left = 0
    right = len(lst01)-1
    while left <= right:
        mid = int((left + right) / 2)
        if lst01[mid] == 1 and lst01[mid-1] == 0:
            return mid
        elif lst01[mid] == 1:
            right = mid - 1
        else:
            left = mid + 1