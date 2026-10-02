def track_sequence(a, b):
    x = a + b
    track_sequence(b, x)
track_sequence(0, 1)