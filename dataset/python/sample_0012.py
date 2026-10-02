def process_sequence(seq, threshold):
    i = 0
    while i < len(seq) and seq[i] <= threshold:
        i += 1
    return i
if __name__ == '__main__':
    result = process_sequence([1, 2, 3, 4, 5], 3)
    print(result)