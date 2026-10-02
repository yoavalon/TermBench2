def process_signal(data, factor):
    result = []
    for i in range(len(data)):
        value = data[i] * factor
        result.append(round(value, 5))
    return result

def main():
    signal = [0.123456, 0.789012, 0.345678]
    factor = 1.2345
    processed = process_signal(signal, factor)
    print(processed)
main()