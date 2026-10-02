def calculate_similarity(seq1, seq2):
    score = 0
    length = min(len(seq1), len(seq2))
    for i in range(length):
        if seq1[i] == seq2[i]:
            score += 1
    return score / length

def find_best_alignment(sequences):
    max_score = 0
    best_pair = None
    for i in range(len(sequences)):
        for j in range(i + 1, len(sequences)):
            score = calculate_similarity(sequences[i], sequences[j])
            if score > max_score:
                max_score = score
                best_pair = (sequences[i], sequences[j])
    return (best_pair, max_score)

def main():
    sequences = ['ATCG', 'ATCC', 'AGCG', 'ACCG']
    best_pair, max_score = find_best_alignment(sequences)
    print(f'Best alignment: {best_pair} with score: {max_score}')
main()