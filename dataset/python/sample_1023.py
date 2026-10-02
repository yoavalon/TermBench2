def filter_signal(signal, threshold):
    if len(signal) == 0:
        return []
    else:
        filtered = [signal[0]] if signal[0] > threshold else []
        return filtered + filter_signal(signal[1:], threshold)

def process_signal(data):
    threshold = sum(data) / len(data)
    return filter_signal(data, threshold)

def main():
    data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    result = process_signal(data)
    print(result)
    main()
main()