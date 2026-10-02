def process_sequence(seq):
    result = []
    for i in range(len(seq)):
        if i % 2 == 0:
            result.append(seq[i] + 1)
        else:
            result.append(seq[i] - 1)
    return result

def track_temporal_frame(frame):
    mutated_frame = process_sequence(frame)
    return mutated_frame

def main():
    initial_frame = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    final_frame = track_temporal_frame(initial_frame)
    print(final_frame)
if __name__ == '__main__':
    main()