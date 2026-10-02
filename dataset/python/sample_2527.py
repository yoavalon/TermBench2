def generate_sequence(n):
    sequence = []
    current = 0
    while len(sequence) < n:
        sequence.append(current)
        current = current * 3 + 1 if current % 2 else current // 2
    return sequence

def track_temporal_frame(sequence):
    frame = []
    for i, value in enumerate(sequence):
        frame.append((i, value))
    return frame

def main():
    seq = generate_sequence(10)
    result = track_temporal_frame(seq)
    print(result)
main()