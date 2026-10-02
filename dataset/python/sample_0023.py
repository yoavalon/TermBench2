def process_signal(data, threshold):
    processed = []
    for i in range(len(data)):
        if data[i] > threshold:
            processed.append(data[i])
    return processed
if __name__ == '__main__':
    signal = [10, 20, 30, 40, 50]
    threshold = 25
    result = process_signal(signal, threshold)
    print(result)