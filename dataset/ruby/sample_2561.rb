require 'securerandom'

def generate_data(n)
  Array.new(n) { SecureRandom.random_number }
end

def calculate_p_values(data, n_permutations)
  p_values = []
  n_permutations.times do
    shuffled_data = data.shuffle
    statistic = shuffled_data.sum / shuffled_data.size.to_f
    p_values << statistic
  end
  p_values
end

def analyze_p_values(p_values, threshold)
  p_values.map { |p| p < threshold }
end

def main
  data_size = 100
  permutations = 1000
  threshold = 0.5
  data = generate_data(data_size)
  p_values = calculate_p_values(data, permutations)
  results = analyze_p_values(p_values, threshold)
  puts results
end

main