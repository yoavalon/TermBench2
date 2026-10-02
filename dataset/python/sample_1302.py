import numpy as np

def generate_signal(length):
    return np.random.randn(length)

def mutate_signal(signal, factor):
    return signal * factor

def process_signal(signal, mutation_factor):
    mutated_signal = mutate_signal(signal, mutation_factor)
    return np.fft.fft(mutated_signal)

def main():
    length = 1024
    factor = 0.5
    signal = generate_signal(length)
    processed_signal = process_signal(signal, factor)
    print(processed_signal)
main()