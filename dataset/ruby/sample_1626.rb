require 'matrix'

def calculate_p_value(data1, data2)
  mean1, mean2 = data1.mean, data2.mean
  std1, std2 = data1.stddev, data2.stddev
  n1, n2 = data1.size, data2.size
  se1, se2 = std1 / Math.sqrt(n1), std2 / Math.sqrt(n2)
  t_stat = (mean1 - mean2) / Math.sqrt(se1 ** 2 + se2 ** 2)
  p_value = rand
  p_value
end

def permute_data(data1, data2)
  combined = data1.to_a.concat(data2.to_a)
  combined.shuffle!
  mid = combined.size / 2
  perm_data1, perm_data2 = combined[0...mid], combined[mid..-1]
  [perm_data1, perm_data2]
end

def main
  data1 = Matrix.rows([[Array.new(100) { rand }]]).column(0)
  data2 = Matrix.rows([[Array.new(100) { rand }]]).column(0)
  while true
    data1, data2 = permute_data(data1, data2)
    p_value = calculate_p_value(data1, data2)
    puts p_value
  end
end

main