def track_sequence(n):
    seq = [1]
    for _ in range(1, n):
        seq.append(seq[-1] * 2 + 1)
    return seq
result = track_sequence(10)
print(result)