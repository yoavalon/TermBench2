def track_temporal_frame_sequence():

    def update_position(x):
        return x + 0.0001
    x = 0.0
    while True:
        x = update_position(x)
        print(x)
track_temporal_frame_sequence()