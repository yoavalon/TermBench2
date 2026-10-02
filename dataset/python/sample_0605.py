def process_signal(data, index=0):
    if index >= len(data):
        return []
    processed = data[index] * 2
    return [processed] + process_signal(data, index + 1)

def main():
    signal = [1, 2, 3, 4, 5]
    result = process_signal(signal)
    print(result)
main()