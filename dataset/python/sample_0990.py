def track_sequence(n, seq=[]):
    seq.append(n)
    return track_sequence(n + 1, seq)
track_sequence(0)