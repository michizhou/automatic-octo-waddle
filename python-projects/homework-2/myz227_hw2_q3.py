def factors(num):
    big_factor_lst = []
    for factor in range(1,int(num ** (1/2.0)) + 1):
        if num % factor == 0:
            yield factor
            if factor ** 2 != num:
                big_factor_lst.append(num // factor)
    for index in reversed(big_factor_lst):
        yield index