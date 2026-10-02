def track_frames():
    x, y = (0, 0)
    while True:
        x, y = (y, x + y)
        print(f'Frame {x}')
track_frames()