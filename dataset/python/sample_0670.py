def recursive_filter(signal, coeff, index=0):
    if index >= len(signal):
        return signal
    signal[index] = coeff * signal[index] + (1 - coeff) * (signal[index - 1] if index > 0 else 0)
    return recursive_filter(signal, coeff, index + 1)

def main():
    signal = [1, 2, 3, 4, 5]
    coeff = 0.5
    filtered_signal = recursive_filter(signal, coeff)
    print(filtered_signal)
main()