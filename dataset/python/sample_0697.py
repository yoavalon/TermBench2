def track_sequence(a, b, n):
    if n == 0:
        return a
    return track_sequence(b, a + b, n - 1)
x = track_sequence(0, 1, 10)
print(x)