def fibs(n):
    first, second = 1, 1
    for index in range(n):
        yield first
        first, second = second, first + second
