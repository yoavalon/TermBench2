def track_sequence_frames():
    x, y = (0, 1)
    while x < 100:
        x, y = (y, x + y)
    return x
if __name__ == '__main__':
    track_sequence_frames()