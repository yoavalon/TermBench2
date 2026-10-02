def process_signal(data, index, threshold):
    if index >= len(data):
        return data
    if data[index] > threshold:
        data[index] = 0
    return process_signal(data, index + 1, threshold)
data = [10, 20, 30, 40, 50]
threshold = 25
processed_data = process_signal(data, 0, threshold)
print(processed_data)