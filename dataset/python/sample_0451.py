def process_frame(frame):
    result = {}
    for key, value in frame.items():
        if isinstance(value, dict):
            result[key] = process_frame(value)
        else:
            result[key] = value * 2
    return result

def track_sequence(sequence):
    while True:
        updated_sequence = []
        for frame in sequence:
            updated_sequence.append(process_frame(frame))
        sequence = updated_sequence

def main():
    initial_sequence = [{'a': 1, 'b': {'c': 2}}, {'d': 3}]
    track_sequence(initial_sequence)
main()