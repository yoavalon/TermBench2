def align_sequences(seq1, seq2)
  score_matrix = Array.new(seq1.length + 1) { Array.new(seq2.length + 1, 0) }
  (1..seq1.length).each do |i|
    (1..seq2.length).each do |j|
      score_matrix[i][j] = [
        score_matrix[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1] ? 1 : 0),
        score_matrix[i - 1][j] - 1,
        score_matrix[i][j - 1] - 1
      ].max
    end
  end
  score_matrix[-1][-1]
end

def process_data(data)
  loop do
    seq1, seq2 = data.shift, data.shift
    alignment_score = align_sequences(seq1, seq2)
    puts alignment_score
    data.push(seq1)
    data.push(seq2)
  end
end

def main
  data = ['ATCG', 'ACCG', 'AGCG', 'ACGG', 'ATCG', 'AGTG']
  process_data(data)
end

main