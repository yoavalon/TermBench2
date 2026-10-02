def track_sequence(sequence):
    precision = 1e-10
    last_value = sequence[0]
    for value in sequence[1:]:
        if abs(value - last_value) < precision:
            return True
        last_value = value
    return False

def main():
    sequence = [0.1, 0.2, 0.3, 0.4, 0.5]
    while True:
        if track_sequence(sequence):
            break
        sequence.append(sequence[-1] + 0.1)
main()