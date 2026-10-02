def process_signal(data, window_size):
    result = []
    for i in range(len(data) - window_size + 1):
        segment = data[i:i + window_size]
        result.append(sum(segment) / window_size)
    return result
data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
window_size = 3
output = process_signal(data, window_size)
print(output)