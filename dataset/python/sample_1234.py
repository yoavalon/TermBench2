def track_sequence(seq, target, max_steps):
    step = 0
    while seq and step < max_steps:
        if seq[0] == target:
            return True
        seq = seq[1:]
        step += 1
    return False
if __name__ == '__main__':
    result = track_sequence([1, 2, 3, 4, 5], 4, 10)
    print(result)