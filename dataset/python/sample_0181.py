def align_sequences(seq1, seq2, max_distance):
    if max_distance < 0:
        return -1
    distance = 0
    i, j = (0, 0)
    while i < len(seq1) and j < len(seq2):
        if seq1[i] != seq2[j]:
            distance += 1
            if distance > max_distance:
                return -1
        i += 1
        j += 1
    return distance

def process_sequences(sequences, max_distance):
    results = []
    for i in range(len(sequences)):
        for j in range(i + 1, len(sequences)):
            result = align_sequences(sequences[i], sequences[j], max_distance)
            results.append(result)
    return results

def main():
    sequences = ['ATCG', 'ACGG', 'TACG', 'GCTA']
    max_distance = 2
    print(process_sequences(sequences, max_distance))
main()