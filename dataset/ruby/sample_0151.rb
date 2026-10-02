def initialize_sequence(seq)
  {'sequence' => seq, 'position' => 0}
end

def align_sequences(seq1, seq2)
  seq1_data = initialize_sequence(seq1)
  seq2_data = initialize_sequence(seq2)
  while seq1_data['position'] < seq1_data['sequence'].length && seq2_data['position'] < seq2_data['sequence'].length
    if seq1_data['sequence'][seq1_data['position']] == seq2_data['sequence'][seq2_data['position']]
      seq1_data['position'] += 1
      seq2_data['position'] += 1
    else
      seq1_data['position'] += 1
    end
  end
  seq1_data['position']
end

def main
  sequence1 = 'AGCTAGCTAGCT'
  sequence2 = 'AGCTAGCTAGCT'
  result = align_sequences(sequence1, sequence2)
  puts result
end

main