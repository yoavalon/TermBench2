def process_signal(data):
    result = []
    for i in range(len(data)):
        if i % 2 == 0:
            result.append(data[i] * 2)
        else:
            result.append(data[i] / 2)
    return result

def analyze_data(stream):
    while True:
        processed = process_signal(stream)
        print(processed)

def main():
    stream = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    analyze_data(stream)
main()