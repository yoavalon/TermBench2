def track_sequence():
    x, y = (0, 1)
    while True:
        print(x, y)
        x, y = (y, x + y)
track_sequence()