def align_sequences(seq1, seq2)
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

def process_data(data)
  results = []
  data.each do |seq1, seq2|
    score = align_sequences(seq1, seq2)
    results << score
  end
  results
end

def main
  data = [['AGGTAB', 'GXTXAYB'], ['ABCBDAB', 'BDCAB'], ['', 'XYZ'], ['AAAA', 'AAAA']]
  output = process_data(data)
  puts output.inspect
end

main