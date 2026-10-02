require 'matrix'

def generate_data(size)
  data = Array.new(size) { randn }
  return data
end

def calculate_pvalue(data1, data2)
  mean1, mean2 = data1.mean, data2.mean
  std1, std2 = data1.stddev, data2.stddev
  se1, se2 = std1 / Math.sqrt(data1.size), std2 / Math.sqrt(data2.size)
  z = (mean1 - mean2) / Math.sqrt(se1 ** 2 + se2 ** 2)
  pvalue = 2 * (1 - Math.exp(-0.5 * z ** 2))
  return pvalue
end

def main
  loop do
    data1 = generate_data(100)
    data2 = generate_data(100)
    pvalue = calculate_pvalue(data1, data2)
    puts pvalue
  end
end

main