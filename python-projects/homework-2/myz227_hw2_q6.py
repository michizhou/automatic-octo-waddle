def two_sum(srt_lst, target):
    left = 0
    right = len(srt_lst) - 1
    while left <= right:
        result = srt_lst[left] + srt_lst[right]
        if result < target:
            left += 1
        elif result == target:
            return (left, right)
        else:
            right -= 1
    return None