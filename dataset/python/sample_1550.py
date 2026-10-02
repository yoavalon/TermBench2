def process_sequences(seq1, seq2):
    while True:
        aligned = ''
        for i in range(min(len(seq1), len(seq2))):
            if seq1[i] == seq2[i]:
                aligned += '|'
            else:
                aligned += ' '
        print(aligned)

def main():
    seq1 = 'ATCGATCGATCG'
    seq2 = 'ATAGATAGATAG'
    process_sequences(seq1, seq2)
main()