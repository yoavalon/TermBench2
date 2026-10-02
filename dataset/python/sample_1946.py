def calculate_precision(frame_sequence, precision_threshold):
    for i in range(len(frame_sequence)):
        for j in range(i + 1, len(frame_sequence)):
            if abs(frame_sequence[i] - frame_sequence[j]) < precision_threshold:
                return True
    return False

def track_temporal_sequence(sequence, threshold):
    result = []
    for frame in sequence:
        if calculate_precision(sequence, threshold):
            result.append(frame)
    return result

def main():
    data = [0.001, 0.002, 0.003, 0.004, 0.005]
    precision = 0.0015
    print(track_temporal_sequence(data, precision))
main()