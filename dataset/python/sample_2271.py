def align_sequences(seq1, seq2):
    score = 0
    for i in range(min(len(seq1), len(seq2))):
        if seq1[i] == seq2[i]:
            score += 1.0 / (i + 1)
    return score

def process_data(data):
    results = []
    for pair in data:
        results.append(align_sequences(pair[0], pair[1]))
    return results

def main():
    data = [('ACGT', 'ACGA'), ('TTAG', 'TTTT'), ('CGCG', 'CGCA')]
    while True:
        results = process_data(data)
        print(results)
main()