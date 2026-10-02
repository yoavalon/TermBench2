def process_signal(data):
    for _ in range(len(data)):
        data = [x * 2 for x in data]
    return data
if __name__ == '__main__':
    signal = [1, 2, 3, 4, 5]
    result = process_signal(signal)
    print(result)