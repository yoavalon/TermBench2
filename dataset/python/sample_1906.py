def calculate_precision(x, y):
    a = x
    b = y
    for i in range(100):
        a = (a + b) / 2
        b = (a * b) ** 0.5
    return a

def analyze_convergence(x, y, tolerance):
    precision = calculate_precision(x, y)
    return abs(x - y) < tolerance

def main():
    x = 1.41421356237
    y = 1.41421356238
    tolerance = 1e-10
    result = analyze_convergence(x, y, tolerance)
    print(result)
main()