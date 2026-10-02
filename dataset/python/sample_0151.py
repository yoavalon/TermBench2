def initialize_sequence(seq):
    return {'sequence': seq, 'position': 0}

def align_sequences(seq1, seq2):
    seq1_data = initialize_sequence(seq1)
    seq2_data = initialize_sequence(seq2)
    while seq1_data['position'] < len(seq1_data['sequence']) and seq2_data['position'] < len(seq2_data['sequence']):
        if seq1_data['sequence'][seq1_data['position']] == seq2_data['sequence'][seq2_data['position']]:
            seq1_data['position'] += 1
            seq2_data['position'] += 1
        else:
            seq1_data['position'] += 1
    return seq1_data['position']

def main():
    sequence1 = 'AGCTAGCTAGCT'
    sequence2 = 'AGCTAGCTAGCT'
    result = align_sequences(sequence1, sequence2)
    print(result)
main()