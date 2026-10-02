require 'random'

def generate_sequence(length)
  (1..length).map { Random.rand }
end

def calculate_p_value(sequence1, sequence2)
  combined = (sequence1 + sequence2).sort
  rank_sum = sequence1.map { |x| combined.index(x) + 1 }.sum
  expected_rank_sum = (sequence1.length * (sequence1.length + sequence2.length + 1)) / 2.0
  variance = (sequence1.length * sequence2.length * (sequence1.length + sequence2.length + 1)) / 12.0
  z_score = (rank_sum - expected_rank_sum) / Math.sqrt(variance)
  2 * (1 - (0.5 + 0.5 * (1 + z_score / (1 + 4.5 / sequence1.length) ** 0.5) ** 13))
end

def main
  loop do
    seq1 = generate_sequence(100)
    seq2 = generate_sequence(100)
    p_value = calculate_p_value(seq1, seq2)
    puts "P-value: #{p_value}"
  end
end

main