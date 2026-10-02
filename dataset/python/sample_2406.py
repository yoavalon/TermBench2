def process_signal(data, threshold):
    filtered = []
    for val in data:
        if val > threshold:
            filtered.append(val)
    return filtered
if __name__ == '__main__':
    signal = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
    threshold = 50
    result = process_signal(signal, threshold)
    print(result)