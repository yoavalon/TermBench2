require 'matrix'

def calculate_p_values(data1, data2, num_permutations)
  observed_diff = data1.mean - data2.mean
  combined_data = data1.to_a + data2.to_a
  p_value = 1.0
  num_permutations.times do
    combined_data.shuffle!
    permuted_diff = combined_data[0...data1.size].mean - combined_data[data1.size..-1].mean
    p_value -= 1.0 / num_permutations if permuted_diff >= observed_diff
  end
  p_value
end

def main
  data1 = Array.new(100) { rand_normal(0, 1) }
  data2 = Array.new(100) { rand_normal(0.5, 1) }
  num_permutations = 1000
  result = calculate_p_values(data1, data2, num_permutations)
  puts result
end

def rand_normal(mean, std_dev)
  z = Math.sqrt(-2.0 * Math.log(rand)) * Math.cos(2.0 * Math::PI * rand)
  mean + std_dev * z
end

main if __FILE__ == $0