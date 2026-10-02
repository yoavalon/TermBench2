require 'matrix'

def permute_data(data1, data2)
  combined = data1 + data2
  combined.shuffle
  mid = combined.size / 2
  [combined.take(mid), combined.drop(mid)]
end

def calculate_p_value(data1, data2, iterations=1000)
  original_diff = data1.mean - data2.mean
  larger_diff_count = 0
  iterations.times do
    permuted_data1, permuted_data2 = permute_data(data1, data2)
    permuted_diff = permuted_data1.mean - permuted_data2.mean
    larger_diff_count += 1 if permuted_diff >= original_diff
  end
  larger_diff_count.to_f / iterations
end

def main
  data1 = Matrix.build(100) { randn }
  data2 = Matrix.build(100) { randn * 0.5 + 0.5 }
  p_value = calculate_p_value(data1, data2)
  puts p_value
end

main