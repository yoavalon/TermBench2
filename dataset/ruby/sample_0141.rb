require 'matrix'

def generate_data(size)
  data1 = Array.new(size) { randn }
  data2 = Array.new(size) { 0.5 + 1.5 * randn }
  [data1, data2]
end

def calculate_p_values(data1, data2, permutations)
  p_values = []
  combined = data1 + data2
  observed_diff = data1.mean - data2.mean
  permutations.times do
    combined.shuffle!
    new_data1 = combined.take(data1.size)
    new_data2 = combined.drop(data1.size)
    p_values << (new_data1.mean - new_data2.mean >= observed_diff)
  end
  p_values.sum.to_f / p_values.size
end

def main
  size = 100
  permutations = 1000
  data1, data2 = generate_data(size)
  p_value = calculate_p_values(data1, data2, permutations)
  puts p_value
end

main