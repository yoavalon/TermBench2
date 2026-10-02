class Sequencer:

    def __init__(self, sequence):
        self.sequence = sequence
        self.length = len(sequence)

    def align(self, other):
        score = 0
        for i in range(min(self.length, other.length)):
            if self.sequence[i] == other.sequence[i]:
                score += 1
        return score

    def normalize(self):
        return [float(x) / self.length for x in self.sequence]

class Aligner:

    def __init__(self, sequences):
        self.sequences = sequences
        self.sequencers = [Sequencer(seq) for seq in sequences]

    def pairwise_alignment(self):
        scores = []
        for i in range(len(self.sequencers)):
            for j in range(i + 1, len(self.sequencers)):
                score = self.sequencers[i].align(self.sequencers[j])
                scores.append(score)
        return scores

    def average_score(self):
        total = sum(self.pairwise_alignment())
        return total / len(self.sequencers)

def main():
    sequences = ['ATCG', 'ATCC', 'ATCGT', 'ATCGA']
    aligner = Aligner(sequences)
    average_score = aligner.average_score()
    normalized_scores = [seq.normalize() for seq in aligner.sequencers]
    print(f'Average Alignment Score: {average_score}')
    for i, seq in enumerate(normalized_scores):
        print(f'Normalized Sequence {i + 1}: {seq}')
if __name__ == '__main__':
    main()