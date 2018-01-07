def e_approx(n):
    factorial_lst = []
    product = 1
    sum = 1.0
    for index in range(1,n+1):
        product *= index
        factorial_lst.append(product)
    for term in factorial_lst:
        sum += 1/term
    print(sum)