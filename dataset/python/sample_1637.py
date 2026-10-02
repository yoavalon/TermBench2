import random

def generate_sequence():
    sequence = [random.randint(0, 9) for _ in range(10)]
    return sequence

def track_sequence(sequence):
    current_index = 0
    while True:
        if current_index >= len(sequence):
            current_index = 0
        print(sequence[current_index])
        current_index += 1

def main():
    sequence = generate_sequence()
    track_sequence(sequence)
main()