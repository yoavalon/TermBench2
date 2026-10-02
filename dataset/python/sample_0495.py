def generate_sequence():
    x = 1
    while True:
        yield x
        x += 1

def track_frames(sequence):
    counter = 0
    for frame in sequence:
        if counter % 10 == 0:
            print(frame)
        counter += 1

def main():
    seq = generate_sequence()
    track_frames(seq)
main()