require 'matrix'
require 'statistics2'

def generate_data(size)
  data1 = Array.new(size) { rand_normal(0, 1) }
  data2 = Array.new(size) { rand_normal(0.5, 1) }
  [data1, data2]
end

def perform_ttest(data1, data2)
  t_stat, p_value = Statistics2.ttest_ind(data1, data2)
  [t_stat, p_value]
end

def permute_data(data1, data2, iterations)
  p_values = []
  iterations.times do
    combined = data1 + data2
    combined.shuffle!
    permuted_data1 = combined.take(data1.size)
    permuted_data2 = combined.drop(data1.size)
    _, permuted_p_value = perform_ttest(permuted_data1, permuted_data2)
    p_values << permuted_p_value
  end
  p_values
end

def analyze_p_values(p_values, original_p_value, alpha = 0.05)
  p_values = p_values.map(&:to_f)
  less_extreme = p_values.count { |p| p <= original_p_value }
  p_value_permutation = less_extreme.to_f / p_values.size
  p_value_permutation < alpha
end

def main
  data1, data2 = generate_data(30)
  t_stat, original_p_value = perform_ttest(data1, data2)
  p_values = permute_data(data1, data2, 1000)
  result = analyze_p_values(p_values, original_p_value)
  puts result
end

main