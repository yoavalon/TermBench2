def track_sequence():
    frame = 0
    while True:
        frame += 1
        if frame % 100 == 0:
            print(frame)
track_sequence()