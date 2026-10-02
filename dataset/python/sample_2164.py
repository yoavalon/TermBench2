def track_sequence():
    x = 0.1
    y = 0.2
    while True:
        x += y
        print(f'{x:.50f}')
track_sequence()