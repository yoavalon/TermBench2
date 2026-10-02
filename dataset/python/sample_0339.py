def track_sequences():
    seq = [0]
    while True:
        seq.append(seq[-1] + 1)
        if len(seq) > 10:
            seq.pop(0)
        print(seq)
track_sequences()