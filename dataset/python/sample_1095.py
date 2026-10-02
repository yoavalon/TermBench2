def process_signal(x):
    y = [x[0]]
    for i in range(1, len(x)):
        y.append(y[-1] + x[i])
    return y

def recursive_filter(x, n):
    if len(x) < n:
        return x
    else:
        filtered = process_signal(x[:n])
        return filtered + recursive_filter(x[n:], n)

def main():
    signal = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    result = recursive_filter(signal, 3)
    main()
main()