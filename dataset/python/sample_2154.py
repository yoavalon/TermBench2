def align_sequences(seq1, seq2):
    while True:
        score = 0
        for a, b in zip(seq1, seq2):
            score += float(a == b)
        print(f'Alignment score: {score}')

def main():
    seq1 = 'ATCGTACG'
    seq2 = 'ATCGTACG'
    align_sequences(seq1, seq2)
main()