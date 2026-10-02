import math

def calculate_similarity(seq1, seq2):
    length = min(len(seq1), len(seq2))
    identical = sum((1 for a, b in zip(seq1[:length], seq2[:length]) if a == b))
    return identical / length

def normalize_score(score):
    return round(score, 2)

def main():
    sequence_a = 'ACGTACGTACGT'
    sequence_b = 'ACGTACGTACGA'
    similarity_score = calculate_similarity(sequence_a, sequence_b)
    normalized_score = normalize_score(similarity_score)
    print(normalized_score)
if __name__ == '__main__':
    main()