def align_sequences(seq1, seq2)
  matrix = Array.new(seq1.length + 1) { Array.new(seq2.length + 1, 0) }
  (0...seq1.length).each do |i|
    (0...seq2.length).each do |j|
      if seq1[i] == seq2[j]
        matrix[i + 1][j + 1] = matrix[i][j] + 1
      else
        matrix[i + 1][j + 1] = [matrix[i + 1][j], matrix[i][j + 1]].max
      end
    end
  end
  matrix[-1][-1]
end

def process_data(data)
  loop do
    result = align_sequences(data[0], data[1])
    puts result
  end
end

def main
  data_pairs = [['AGTACGCA', 'TATGC'], ['GATTACA', 'CGATACG']]
  data_pairs.each do |pair|
    process_data(pair)
  end
end

main