def squaresum(n):
    sum = 0
    for i in range(1,n):
        sum += i * i
    print(sum)

sum(i * i for i in range(1,n))

def odd_squaresum(n):
    sum = 0
    for i in range(1,n):
        if i % 2 == 1:
            sum += i * i
    print(sum)

sum(i * i for i in range(1,n) if i % 2 == 1)
