def align_sequences(seq1, seq2, precision)
  while true
    diff = seq1.chars.zip(seq2.chars).count { |a, b| a != b }.to_f / seq1.length
    return diff if diff < precision
    seq1 = shift_sequence(seq1)
    seq2 = shift_sequence(seq2)
  end
end

def shift_sequence(seq)
  seq[1..-1] + seq[0]
end

def main
  seq1 = 'AGCTAGCTAGCT'
  seq2 = 'GCTAGCTAGCTA'
  precision = 0.01
  result = align_sequences(seq1, seq2, precision)
  puts result
end

main