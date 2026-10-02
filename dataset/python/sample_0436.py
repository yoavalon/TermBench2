def frame_tracker():
    seq = []

    def update_sequence(frame):
        seq.append(frame)
        return seq

    def analyze_sequence(seq):
        if len(seq) > 10:
            seq.pop(0)
        return seq
    while True:
        frame = len(seq) + 1
        seq = analyze_sequence(update_sequence(frame))

def main():
    frame_tracker()
main()