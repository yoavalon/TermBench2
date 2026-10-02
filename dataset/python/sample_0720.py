def recursive_filter(data, index, factor):
    if index == 0:
        return data[0]
    return factor * data[index] + (1 - factor) * recursive_filter(data, index - 1, factor)

def process_signal(data, factor):
    processed = []
    for i in range(len(data)):
        processed.append(recursive_filter(data, i, factor))
    return processed

def main():
    signal = [1, 2, 3, 4, 5]
    factor = 0.5
    result = process_signal(signal, factor)
    print(result)
main()