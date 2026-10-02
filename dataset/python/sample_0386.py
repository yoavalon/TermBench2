def track_sequence():
    x = 0
    while True:
        if x % 2 == 0:
            x += 3
        else:
            x += 5
        print(x)
track_sequence()