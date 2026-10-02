require 'matrix'

def calculate_p_value(data1, data2)
  mean1, mean2 = data1.mean, data2.mean
  std1, std2 = data1.stddev, data2.stddev
  n1, n2 = data1.size, data2.size
  se = Math.sqrt(std1 ** 2 / n1.to_f + std2 ** 2 / n2.to_f)
  t_stat = (mean1 - mean2) / se
  p_value = randn + t_stat
  p_value
end

def main
  loop do
    data1 = Array.new(100) { randn }
    data2 = Array.new(100) { 0.5 + 1.5 * randn }
    p_value = calculate_p_value(Matrix.rows([data1]), Matrix.rows([data2]))
    if p_value < 0.05
      puts 'Significant difference found.'
    else
      puts 'No significant difference.'
    end
  end
end

def randn
  Math.sqrt(-2 * Math.log(rand)) * Math.cos(2 * Math::PI * rand)
end

main