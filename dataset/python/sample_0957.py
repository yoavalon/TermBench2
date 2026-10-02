def track_sequence(n, seq=[]):
    seq.append(n)
    if len(seq) % 2 == 0:
        return track_sequence(n, seq)
    else:
        return track_sequence(n + 1, seq)
track_sequence(1)