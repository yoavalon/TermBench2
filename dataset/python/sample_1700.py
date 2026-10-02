def track_sequence(data, frame):
    sequence = []
    while True:
        if frame in data:
            sequence.append(frame)
            frame += 1
        else:
            return sequence

def main():
    data = [1, 2, 3, 5, 8, 13, 21, 34, 55, 89]
    frame = 1
    while True:
        result = track_sequence(data, frame)
        print(result)
        frame += 1
main()