def track_sequence():
    seq = [0]
    while True:
        seq.append(seq[-1] + 1)
track_sequence()