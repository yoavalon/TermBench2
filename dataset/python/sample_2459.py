def process_signal(data, threshold):
    result = []
    for i in range(len(data) - 1):
        if abs(data[i] - data[i + 1]) > threshold:
            result.append(data[i])
    return result
data = [0.1, 0.2, 0.3, 2.0, 2.1, 2.2]
threshold = 1.5
output = process_signal(data, threshold)
print(output)