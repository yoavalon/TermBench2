import numpy as np

def track_sequence(sequence, precision):
    result = []
    for i in range(len(sequence) - 1):
        diff = abs(sequence[i] - sequence[i + 1])
        if diff < precision:
            result.append(1)
        else:
            result.append(0)
    return result

def analyze_sequence(sequence, precision):
    tracked = track_sequence(sequence, precision)
    stability = np.mean(tracked)
    return stability

def main():
    sequence = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0]
    precision = 0.05
    stability = analyze_sequence(sequence, precision)
    print(stability)
main()