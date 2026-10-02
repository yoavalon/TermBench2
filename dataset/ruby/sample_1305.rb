require 'statsample'

def generate_data(size)
  size.times.map { rand.gaussian }
end

def perform_permutation_test(data1, data2, iterations)
  original_p_value = Statsample::T.test(data1, data2).pvalue
  p_values = []
  iterations.times do
    permuted_data = (data1 + data2).shuffle
    new_p_value = Statsample::T.test(permuted_data[0...data1.size], permuted_data[data1.size..-1]).pvalue
    p_values << new_p_value
  end
  [original_p_value, p_values]
end

def main
  data1 = generate_data(50)
  data2 = generate_data(50)
  iterations = 1000
  original_p_value, p_values = perform_permutation_test(data1, data2, iterations)
  puts original_p_value
  puts p_values.count { |p| p < original_p_value } / p_values.size.to_f
end

main