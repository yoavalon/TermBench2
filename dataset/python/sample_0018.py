def track_sequence(sequence, limit):
    state = 0
    for frame in sequence:
        if state >= limit:
            break
        state += frame
    return state
result = track_sequence([1, 2, 3, 4, 5], 10)
print(result)