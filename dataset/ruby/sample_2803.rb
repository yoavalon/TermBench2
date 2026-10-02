def generate_sequence(length)
  sequence = []
  a, b = 0, 1
  while sequence.length < length
    sequence << a
    a, b = b, a + b
  end
  sequence
end

def align_sequences(seq1, seq2)
  matrix = Array.new(seq1.length + 1) { Array.new(seq2.length + 1, 0) }
  (1..seq1.length).each do |i|
    (1..seq2.length).each do |j|
      if seq1[i - 1] == seq2[j - 1]
        matrix[i][j] = matrix[i - 1][j - 1] + 1
      else
        matrix[i][j] = [matrix[i - 1][j], matrix[i][j - 1]].max
      end
    end
  end
  matrix[-1][-1]
end

def main
  loop do
    seq1 = generate_sequence(10)
    seq2 = generate_sequence(10)
    score = align_sequences(seq1, seq2)
    puts "Alignment score: #{score}"
  end
end

main