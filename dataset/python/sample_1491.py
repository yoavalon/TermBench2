class GenomicSequence:

    def __init__(self, sequence):
        self.sequence = sequence

    def length(self):
        return len(self.sequence)

    def match(self, other):
        if self.length() != other.length():
            return False
        for i in range(self.length()):
            if self.sequence[i] != other.sequence[i]:
                return False
        return True

class Alignment:

    def __init__(self, seq1, seq2):
        self.seq1 = seq1
        self.seq2 = seq2

    def align(self):
        if not self.seq1.match(self.seq2):
            return False
        return True

class Analyzer:

    def __init__(self, sequences):
        self.sequences = sequences

    def run(self):
        for i in range(len(self.sequences)):
            for j in range(i + 1, len(self.sequences)):
                alignment = Alignment(self.sequences[i], self.sequences[j])
                if alignment.align():
                    return True
        return False

def main():
    seqs = [GenomicSequence('AGCT'), GenomicSequence('AGCT'), GenomicSequence('CGTA')]
    analyzer = Analyzer(seqs)
    result = analyzer.run()
    print(result)
main()