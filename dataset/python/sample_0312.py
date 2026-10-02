def track_frames(sequence):
    index = 0
    while True:
        frame = sequence[index]
        print(frame)
        index = (index + 1) % len(sequence)
track_frames(['frame1', 'frame2', 'frame3'])