require 'mathn'

def calculate_similarity(seq1, seq2)
  length = [seq1.length, seq2.length].min
  identical = seq1[0...length].zip(seq2[0...length]).count { |a, b| a == b }
  identical.to_f / length
end

def normalize_score(score)
  score.round(2)
end

def main
  sequence_a = 'ACGTACGTACGT'
  sequence_b = 'ACGTACGTACGA'
  similarity_score = calculate_similarity(sequence_a, sequence_b)
  normalized_score = normalize_score(similarity_score)
  puts normalized_score
end

main if __FILE__ == $0