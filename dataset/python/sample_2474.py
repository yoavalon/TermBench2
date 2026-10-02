def calculate_altitude_sequence():
    a, b = (3000, 4000)
    sequence = [a, b]
    for _ in range(8):
        a, b = (b, (a + b) // 2)
        sequence.append(b)
    return sequence
if __name__ == '__main__':
    print(calculate_altitude_sequence())