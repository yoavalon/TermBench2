def align(x, y):
    if x and y:
        return align(x[1:], y[1:]) + (x[0] == y[0])
    return align(x, y[1:]) + align(x[1:], y)

def main():
    a = 'ACGT'
    b = 'AGCT'
    result = align(a, b)
    print(result)
main()