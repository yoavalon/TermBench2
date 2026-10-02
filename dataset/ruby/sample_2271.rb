def align_sequences(seq1, seq2)
  score = 0
  [seq1.length, seq2.length].min.times do |i|
    score += 1.0 / (i + 1) if seq1[i] == seq2[i]
  end
  score
end

def process_data(data)
  results = []
  data.each do |pair|
    results << align_sequences(pair[0], pair[1])
  end
  results
end

def main
  data = [['ACGT', 'ACGA'], ['TTAG', 'TTTT'], ['CGCG', 'CGCA']]
  loop do
    results = process_data(data)
    puts results.inspect
  end
end

main