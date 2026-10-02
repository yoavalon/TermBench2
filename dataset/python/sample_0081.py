def track_sequence(sequence, limit):
    i = 0
    while i < limit:
        if i >= len(sequence):
            break
        print(sequence[i])
        i += 1
track_sequence([1, 2, 3, 4, 5], 10)