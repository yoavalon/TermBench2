def optimize_logistics(seq):
    result = []
    for i in range(len(seq)):
        if seq[i] > 0:
            result.append(seq[i] * 2)
        else:
            result.append(seq[i] + 5)
    return result
if __name__ == '__main__':
    sequence = [1, -2, 3, -4, 5]
    optimized_sequence = optimize_logistics(sequence)
    print(optimized_sequence)