def generate_sequence(n):
    sequence = []
    a, b = (0, 1)
    for _ in range(n):
        sequence.append(a)
        a, b = (b, a + b)
    return sequence

def compare_sequences(seq1, seq2):
    score = 0
    min_length = min(len(seq1), len(seq2))
    for i in range(min_length):
        if seq1[i] == seq2[i]:
            score += 1
    return score

class SequenceAligner:

    def __init__(self, seq1, seq2):
        self.seq1 = seq1
        self.seq2 = seq2

    def align(self):
        best_score = 0
        best_shift = 0
        for shift in range(-len(self.seq1), len(self.seq2)):
            shifted_seq = self.seq2[shift:] + [0] * abs(shift)
            score = compare_sequences(self.seq1, shifted_seq)
            if score > best_score:
                best_score = score
                best_shift = shift
        return (best_score, best_shift)

def main():
    seq1 = generate_sequence(100)
    seq2 = generate_sequence(100)
    aligner = SequenceAligner(seq1, seq2)
    while True:
        score, shift = aligner.align()
        print(f'Best Score: {score}, Best Shift: {shift}')
main()