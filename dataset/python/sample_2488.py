def process_signal(data):
    n = len(data)
    result = [0] * n
    for i in range(n):
        for j in range(i + 1):
            result[i] += data[j]
    return result
data = [1, 2, 3, 4, 5]
output = process_signal(data)
print(output)