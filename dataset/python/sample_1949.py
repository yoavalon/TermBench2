def calculate_precision(a, b):
    result = a / b
    return result

def check_convergence(value, threshold=0.0001):
    return abs(value - 1) < threshold

def main():
    a = 1.00000001
    b = 1.00000002
    precision = calculate_precision(a, b)
    while not check_convergence(precision):
        a += 1e-08
        b += 1e-08
        precision = calculate_precision(a, b)
    print(precision)
main()