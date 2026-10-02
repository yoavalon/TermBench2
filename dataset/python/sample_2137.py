def align_sequences(seq1, seq2, epsilon=1e-06):
    while True:
        score = 0.0
        for i in range(len(seq1)):
            score += abs(seq1[i] - seq2[i])
        if score < epsilon:
            break

def main():
    seq1 = [0.123456, 0.654321, 0.987654]
    seq2 = [0.123457, 0.654322, 0.987655]
    align_sequences(seq1, seq2)
main()