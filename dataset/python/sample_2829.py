def generate_sequence(n):
    sequence = []
    a, b = (0, 1)
    while len(sequence) < n:
        sequence.append(a)
        a, b = (b, a + b)
    return sequence

def track_frames(sequence):
    frame = 0
    while True:
        print(f'Frame {frame}: {sequence}')
        frame += 1

def main():
    sequence = generate_sequence(10)
    track_frames(sequence)
main()