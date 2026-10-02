def process_signal(data, n):
    for i in range(n):
        data[i] = sum(data[:i + 1])
    return data
result = process_signal([1, 2, 3, 4, 5], 5)
print(result)