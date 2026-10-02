require 'random'
require 'mathn'

def generate_sequence(n, seed)
  Random.srand(seed)
  sequence = Array.new(n) { Random.gaussian(0, 1) }
  sequence
end

def calculate_p_value(sequence)
  n = sequence.length
  mean = sequence.sum / n.to_f
  variance = sequence.map { |x| (x - mean) ** 2 }.sum / n.to_f
  std_dev = Math.sqrt(variance)
  z_score = mean / (std_dev / Math.sqrt(n.to_f))
  p_value = 1 - Math.erf(z_score / Math.sqrt(2))
  p_value
end

def perform_permutations(sequence, iterations)
  p_values = []
  iterations.times do
    sequence.shuffle!
    p_values << calculate_p_value(sequence)
  end
  p_values
end

def analyze_p_values(p_values)
  p_values.sort!
  median_p_value = p_values[p_values.length / 2]
  median_p_value
end

def main
  sequence_length = 100
  seed_value = 42
  num_iterations = 1000
  sequence = generate_sequence(sequence_length, seed_value)
  p_values = perform_permutations(sequence, num_iterations)
  median_p_value = analyze_p_values(p_values)
  puts "Median p-value: #{median_p_value}"
end

main if __FILE__ == $0