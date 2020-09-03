def fibo(n):
    a = 0
    b = 1
    if n == 0:
        return a
    elif n == 1:
        return b
    else:
        f = a + b
        for i in range(2, n):
            a = b
            b = f
            f = a + b
        return f

def main():
    for i in range(11):
        print(fibo(i), end=" ")

main()