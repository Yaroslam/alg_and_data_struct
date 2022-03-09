def sum(a, b):
    return a + b


def minus(a, b):
    return a - b


def mult(a, b):
    return a * b


def div(a, b):
    if b == 0:
        print("Захотел поделить на 0? Молодец")
        raise SystemExit(1)
    else:
        return a / b


def power(a, n):
    return a**n
