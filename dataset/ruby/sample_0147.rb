require 'matrix'
require 'statistics2'

def generate_data(size)
  Statistics2.distribution(:normal).random(size)
end

def calculate_p_value(sample1, sample2)
  t_stat, p_value = Statistics2::T.test(sample1, sample2)
  p_value
end

def permutation_test(sample1, sample2, iterations)
  original_p = calculate_p_value(sample1, sample2)
  larger_count = 0
  (1..iterations).each do
    permuted = sample1 + sample2
    permuted.shuffle!
    new_p = calculate_p_value(permuted[0...sample1.size], permuted[sample1.size..-1])
    larger_count += 1 if new_p >= original_p
  end
  larger_count.to_f / iterations
end

def main
  sample1 = generate_data(50)
  sample2 = generate_data(50)
  iterations = 1000
  p_value = permutation_test(sample1, sample2, iterations)
  puts p_value
end

main