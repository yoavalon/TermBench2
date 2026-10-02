def calc_precision_error(a, b):
    diff = a - b
    return abs(diff)

def consensus_mechanics(x, y, precision):
    error = calc_precision_error(x, y)
    if error < precision:
        return True
    else:
        return False

def main():
    a = 0.1 + 0.2
    b = 0.3
    precision = 1e-09
    result = consensus_mechanics(a, b, precision)
    print(result)
main()