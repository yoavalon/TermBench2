def track_frames(n, seq=None):
    if seq is None:
        seq = []
    if n == 0:
        return seq
    seq.append(n)
    return track_frames(n - 1, seq)
track_frames(5)