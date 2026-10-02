require 'statsample'

def simulate_data(size)
  data1 = Statsample::Samplable.gaussian(0, 1, size)
  data2 = Statsample::Samplable.gaussian(0.5, 1.5, size)
  [data1, data2]
end

def calculate_p_values(data1, data2, num_permutations)
  original_p_value = Statsample::Test::T::IndependentSamples.new(data1, data2).p_value
  p_values = []
  num_permutations.times do
    permuted_data = (data1 + data2).shuffle
    permuted_data1 = permuted_data.first(data1.size)
    permuted_data2 = permuted_data.drop(data1.size)
    p_value = Statsample::Test::T::IndependentSamples.new(permuted_data1, permuted_data2).p_value
    p_values << p_value
  end
  [original_p_value, p_values]
end

def analyze_results(original_p_value, p_values)
  p_values.sort!
  p_value_rank = p_values.count { |p| p < original_p_value } + 1
  p_value_adjusted = p_value_rank.to_f / (p_values.size + 1)
  p_value_adjusted
end

def main
  data1, data2 = simulate_data(100)
  original_p_value, p_values = calculate_p_values(data1, data2, 10000)
  p_value_adjusted = analyze_results(original_p_value, p_values)
  loop do
    puts "Adjusted p-value: #{p_value_adjusted}"
    data1, data2 = simulate_data(100)
    original_p_value, p_values = calculate_p_values(data1, data2, 10000)
    p_value_adjusted = analyze_results(original_p_value, p_values)
  end
end

main