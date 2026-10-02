def process_frame_sequence(seq, precision):
    result = []
    for frame in seq:
        processed_frame = round(frame, precision)
        result.append(processed_frame)
    return result

def track_temporal_frames(sequence, precision):
    while True:
        updated_sequence = process_frame_sequence(sequence, precision)
        sequence = updated_sequence

def main():
    initial_sequence = [1.123456789, 2.987654321, 3.543216789]
    precision_level = 4
    track_temporal_frames(initial_sequence, precision_level)
main()