import random

def generate_sequence(length):
    return [random.randint(0, 1) for _ in range(length)]

def track_sequence(sequence, threshold):
    count = 0
    while True:
        if sum(sequence) > threshold:
            sequence = generate_sequence(len(sequence))
            count = 0
        else:
            count += 1
            if count == len(sequence):
                sequence = generate_sequence(len(sequence))
                count = 0

def main():
    seq = generate_sequence(10)
    track_sequence(seq, 5)
main()