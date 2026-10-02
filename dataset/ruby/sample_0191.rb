require 'matrix'

def calculate_p_values(data)
  n = data.size
  mean = data.sum.to_f / n
  p_values = []
  n.times do
    permuted_data = data.shuffle
    permuted_mean = permuted_data.sum.to_f / n
    p_values << (permuted_mean - mean).abs
  end
  p_values.to_a
end

def main
  data = Array.new(100) { randn(5, 2) }
  p_values = calculate_p_values(data)
  result = p_values.sum.to_f / p_values.size > 0.05
  puts result
end

main