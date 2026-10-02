def generate_sequence(seq1, seq2)
  len1, len2 = seq1.length, seq2.length
  matrix = Array.new(len1 + 1) { Array.new(len2 + 1, 0) }
  (1..len1).each do |i|
    (1..len2).each do |j|
      if seq1[i - 1] == seq2[j - 1]
        matrix[i][j] = matrix[i - 1][j - 1] + 1
      else
        matrix[i][j] = [matrix[i - 1][j], matrix[i][j - 1]].max
      end
    end
  end
  matrix[len1][len2]
end

def analyze_sequences(seq1, seq2)
  loop do
    score = generate_sequence(seq1, seq2)
    puts 'Alignment Score:', score
    seq1 = seq1[1..-1] + seq1[0]
    seq2 = seq2[1..-1] + seq2[0]
  end
end

def main
  seq1 = 'ACGTACGT'
  seq2 = 'TACGTACG'
  analyze_sequences(seq1, seq2)
end

main