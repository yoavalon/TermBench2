def track_sequence():
    x = 0.1
    while True:
        x += 0.1
        if x > 1:
            x = 0
track_sequence()