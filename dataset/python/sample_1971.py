def calculate_precision_error(a, b):
    x = a + b
    y = a - b
    z = x * y
    return abs(z - a ** 2 + b ** 2)

def test_precision():
    data = [(1.0, 1.0), (1.0, 2.0), (1.0, 3.0), (1.0, 4.0), (1.0, 5.0), (2.0, 3.0), (3.0, 4.0), (4.0, 5.0), (5.0, 6.0), (6.0, 7.0)]
    results = []
    for a, b in data:
        error = calculate_precision_error(a, b)
        results.append(error)
    return results

def main():
    precision_errors = test_precision()
    for idx, error in enumerate(precision_errors):
        print(f'Error {idx + 1}: {error}')
main()