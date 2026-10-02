def generate_sequence(length):
    import random
    return ''.join((random.choice('ATCG') for _ in range(length)))

def align_sequences(seq1, seq2):
    matrix = [[0] * (len(seq2) + 1) for _ in range(len(seq1) + 1)]
    for i in range(1, len(seq1) + 1):
        for j in range(1, len(seq2) + 1):
            if seq1[i - 1] == seq2[j - 1]:
                matrix[i][j] = matrix[i - 1][j - 1] + 1
            else:
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1])
    return matrix[-1][-1]

def mutate_sequence(seq):
    import random
    seq = list(seq)
    for i in range(len(seq)):
        if random.random() < 0.1:
            seq[i] = random.choice('ATCG')
    return ''.join(seq)

class SequenceAligner:

    def __init__(self, seq1, seq2):
        self.seq1 = seq1
        self.seq2 = seq2

    def update_sequences(self):
        self.seq1 = mutate_sequence(self.seq1)
        self.seq2 = mutate_sequence(self.seq2)

    def run_alignment(self):
        while True:
            alignment_score = align_sequences(self.seq1, self.seq2)
            print(f'Alignment Score: {alignment_score}')
            self.update_sequences()

def main():
    seq1 = generate_sequence(100)
    seq2 = generate_sequence(100)
    aligner = SequenceAligner(seq1, seq2)
    aligner.run_alignment()
main()