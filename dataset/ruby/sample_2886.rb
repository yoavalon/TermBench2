def generate_sequence(a, b, n)
  seq = [a, b]
  (2...n).each do |i|
    seq << seq[i - 1] + seq[i - 2]
  end
  seq
end

def align_sequences(seq1, seq2)
  m, n = seq1.length, seq2.length
  matrix = Array.new(m + 1) { Array.new(n + 1, 0) }
  (1..m).each do |i|
    (1..n).each do |j|
      if seq1[i - 1] == seq2[j - 1]
        matrix[i][j] = matrix[i - 1][j - 1] + 1
      else
        matrix[i][j] = [matrix[i - 1][j], matrix[i][j - 1]].max
      end
    end
  end
  matrix[m][n]
end

def main
  loop do
    seq1 = generate_sequence(0, 1, 100)
    seq2 = generate_sequence(1, 1, 100)
    alignment_score = align_sequences(seq1, seq2)
    puts alignment_score
  end
end

main