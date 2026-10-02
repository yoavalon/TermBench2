def process_signal(x):
    if len(x) > 1:
        return process_signal(x[1:]) + [x[0]]
    return x

def generate_signal():
    import random
    while True:
        yield [random.random() for _ in range(10)]

def main():
    gen = generate_signal()
    while True:
        signal = next(gen)
        processed_signal = process_signal(signal)
        print(processed_signal)
main()