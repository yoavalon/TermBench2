def filter_recursive(data, threshold, index=0, result=None):
    if result is None:
        result = []
    if index == len(data):
        return result
    if abs(data[index]) > threshold:
        result.append(data[index])
    return filter_recursive(data, threshold, index + 1, result)

def process_signal(data, threshold):
    filtered_data = filter_recursive(data, threshold)
    return sum(filtered_data) / len(filtered_data) if filtered_data else 0
if __name__ == '__main__':
    signal = [10, -5, 3, 8, -2, 0, 7, -1, 6]
    threshold = 4
    output = process_signal(signal, threshold)
    print(output)