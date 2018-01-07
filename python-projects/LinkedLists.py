def reverse_list1(lnk_lst):
    start = lnk_lst.header
    end = lnk_lst.trailer
    times = len(lnk_lst) // 2
    for i in range(times):
        start = start.next
        end = end.prev
        start.data, end.data = end.data, start.data

def reverse_list2(lnk_lst):
    old_first = lnk_lst.first_node()
    old_last = lnk_lst.last_node()
    current = lnk_lst.header.next

    # Swap next and prev for all nodes of
    # doubly linked list
    while current is not None:
        old_prev = current.prev
        current.prev = current.next
        current.next = old_prev
        current = current.prev

    old_last.prev = lnk_lst.header
    old_first.next = lnk_lst.trailer
    lnk_lst.header.next = old_last
    lnk_lst.trailer.prev = old_first