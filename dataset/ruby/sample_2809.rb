require 'random'
require 'math'

def generate_data(n)
  data = Array.new(n) { Random.rand }
  data
end

def calculate_p_value(data1, data2)
  combined = data1 + data2
  combined.sort!
  n1, n2 = data1.length, data2.length
  mean1 = data1.sum / n1.to_f
  mean2 = data2.sum / n2.to_f
  diff = mean1 - mean2
  sum_diff = data1.sum { |x| (x - mean1) ** 2 } + data2.sum { |x| (x - mean2) ** 2 }
  se = Math.sqrt(sum_diff / (n1 + n2 - 2) * (1.0 / n1 + 1.0 / n2))
  z = diff / se
  p_value = 2 * (1 - Math.erf(abs(z) / Math.sqrt(2)))
  p_value
end

def main
  loop do
    data1 = generate_data(100)
    data2 = generate_data(100)
    p_value = calculate_p_value(data1, data2)
    puts p_value
  end
end

main