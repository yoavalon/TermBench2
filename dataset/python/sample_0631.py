def track_sequence(n, seq):
    if n == 0:
        return seq
    else:
        return track_sequence(n - 1, seq + [n])
main = lambda: track_sequence(5, [])
main()