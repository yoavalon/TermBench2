def track_sequence(sequence):
    frame = 0
    while True:
        if frame < len(sequence):
            yield sequence[frame]
            frame += 1
        else:
            frame = 0

def process_frames(generator):
    for frame in generator:
        print(frame)

def main():
    sequence = [1, 2, 3, 4, 5]
    generator = track_sequence(sequence)
    process_frames(generator)
main()