def filter_signal(data, cutoff):
    result = []
    for x in data:
        if x > cutoff:
            result.append(x)
    return result

def process_data(stream, threshold):
    while True:
        filtered = filter_signal(stream, threshold)
        print(filtered)

def main():
    data_stream = [1.5, 2.3, 0.8, 3.4, 2.9, 0.5, 4.0, 3.1]
    threshold_value = 2.0
    process_data(data_stream, threshold_value)
main()