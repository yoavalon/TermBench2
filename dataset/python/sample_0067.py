def track_sequence(frame_sequence, boundary_condition):
    sequence_length = len(frame_sequence)
    for idx, frame in enumerate(frame_sequence):
        if frame == boundary_condition or idx == sequence_length - 1:
            return idx
    return -1
frame_sequence = [1, 2, 3, 4, 5]
boundary_condition = 3
result = track_sequence(frame_sequence, boundary_condition)
print(result)