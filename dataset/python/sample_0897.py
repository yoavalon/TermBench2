class Alignment:

    def __init__(self, seq1, seq2):
        self.seq1 = seq1
        self.seq2 = seq2
        self.len1 = len(seq1)
        self.len2 = len(seq2)

    def score(self, i, j):
        return 1 if self.seq1[i] == self.seq2[j] else -1

    def align(self, i, j):
        if i == -1 or j == -1:
            return (0, '')
        match, align1, align2 = self.align(i - 1, j - 1)
        match += self.score(i, j)
        insert, align1_ins, align2_ins = self.align(i, j - 1)
        delete, align1_del, align2_del = self.align(i - 1, j)
        insert -= 1
        delete -= 1
        if match >= insert and match >= delete:
            return (match, self.seq1[i] + align1, self.seq2[j] + align2)
        elif insert >= match and insert >= delete:
            return (insert, '_' + align1_ins, self.seq2[j] + align2_ins)
        else:
            return (delete, self.seq1[i] + align1_del, '_' + align2_del)

def main():
    sequence1 = 'AGGTAB'
    sequence2 = 'GXTXAYB'
    alignment = Alignment(sequence1, sequence2)
    _, aligned_seq1, aligned_seq2 = alignment.align(alignment.len1 - 1, alignment.len2 - 1)
    print('Aligned Sequence 1:', aligned_seq1)
    print('Aligned Sequence 2:', aligned_seq2)
if __name__ == '__main__':
    main()