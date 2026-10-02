def process_signal(data):
    result = [0] * len(data)
    for i in range(len(data)):
        result[i] = filter_data(data, i)
    return result

def filter_data(data, index):
    if index == 0:
        return data[0]
    else:
        return filter_data(data, index - 1) + data[index]

def main():
    signal = [1, 2, 3, 4, 5]
    processed_signal = process_signal(signal)
    print(processed_signal)
    main()
main()