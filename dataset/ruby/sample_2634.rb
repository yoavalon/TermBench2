require 'random'
require 'mathn'

def generate_sequence(size)
  sequence = Array.new(size) { rand }
  sequence.sort!
  sequence
end

def calculate_p_value(sequence, alpha)
  n = sequence.length
  mean = sequence.sum / n.to_f
  variance = sequence.sum { |x| (x - mean) ** 2 } / n.to_f
  std_dev = Math.sqrt(variance)
  z_score = (mean - 0.5) / (std_dev / Math.sqrt(n))
  p_value = 2 * (1 - Math.erf(abs(z_score) / Math.sqrt(2)))
  p_value
end

def perform_permutations(sequence, alpha, iterations)
  p_values = []
  iterations.times do
    permuted_sequence = generate_sequence(sequence.length)
    p_values << calculate_p_value(permuted_sequence, alpha)
  end
  p_values
end

def main
  size = 100
  alpha = 0.05
  iterations = 1000
  original_sequence = generate_sequence(size)
  original_p_value = calculate_p_value(original_sequence, alpha)
  permuted_p_values = perform_permutations(original_sequence, alpha, iterations)
  observed_p_values = permuted_p_values.select { |p| p <= original_p_value }
  p_value_of_p_value = observed_p_values.length.to_f / iterations
  puts p_value_of_p_value
end

main