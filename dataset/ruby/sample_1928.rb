require 'matrix'

def align_sequences(seq1, seq2, precision)
  def calculate_score(a, b)
    a.zip(b).map { |x, y| x == y ? 1 : -1 }.sum
  end

  max_score = -Float::INFINITY
  best_alignment = nil
  (seq1.size - seq2.size + 1).times do |i|
    (seq2.size - seq1.size + 1).times do |j|
      subseq1 = seq1.to_a[i, seq2.size]
      subseq2 = seq2.to_a[j, seq1.size]
      score = calculate_score(subseq1, subseq2)
      if score > max_score
        max_score = score
        best_alignment = [subseq1, subseq2]
      end
    end
  end
  [best_alignment, max_score]
end

def main
  seq1 = Vector[*[0.1, 0.2, 0.3, 0.4, 0.5]]
  seq2 = Vector[*[0.1, 0.2, 0.3, 0.4, 0.5]]
  precision = 1e-09
  alignment, score = align_sequences(seq1, seq2, precision)
  puts "Alignment: #{alignment} Score: #{score}"
end

main