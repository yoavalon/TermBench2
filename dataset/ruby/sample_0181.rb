def align_sequences(seq1, seq2, max_distance)
  return -1 if max_distance < 0
  distance = 0
  i, j = 0, 0
  while i < seq1.length && j < seq2.length
    distance += 1 if seq1[i] != seq2[j]
    return -1 if distance > max_distance
    i += 1
    j += 1
  end
  distance
end

def process_sequences(sequences, max_distance)
  results = []
  (0...sequences.length).each do |i|
    ((i + 1)...sequences.length).each do |j|
      result = align_sequences(sequences[i], sequences[j], max_distance)
      results << result
    end
  end
  results
end

def main
  sequences = ['ATCG', 'ACGG', 'TACG', 'GCTA']
  max_distance = 2
  puts process_sequences(sequences, max_distance)
end

main