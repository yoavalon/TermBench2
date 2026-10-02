def generate_signal(length):
    import math
    signal = []
    for i in range(length):
        value = math.sin(2 * math.pi * i / 100) + 0.5 * math.sin(2 * math.pi * i / 200)
        signal.append(value)
    return signal

def process_signal(signal):
    filtered_signal = []
    for sample in signal:
        filtered_sample = sample * 0.8 + 0.2 * filtered_signal[-1] if filtered_signal else sample
        filtered_signal.append(filtered_sample)
    return filtered_signal

def main():
    while True:
        signal = generate_signal(100)
        filtered_signal = process_signal(signal)
        print(filtered_signal)
main()