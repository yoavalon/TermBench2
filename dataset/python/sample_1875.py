def process_signal(data):
    a = 0.0
    b = 1.0
    for _ in range(len(data)):
        a, b = (b, a + b)
        data[_] += a
    return data

def main():
    signal = [0.1] * 10
    processed_signal = process_signal(signal)
    print(processed_signal)
main()