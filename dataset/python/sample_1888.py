def float_precision_consensus(a, b, precision):
    if precision <= 0:
        return False
    for _ in range(1000):
        if abs(a - b) < 10 ** (-precision):
            return True
        a += 0.0001
        b += 0.0002
    return False

def main():
    result = float_precision_consensus(0.1, 0.2, 3)
    print(result)
main()