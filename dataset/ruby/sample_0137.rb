require 'statistics2'

def generate_data(size)
  data = Array.new(size) { randn }
  return data
end

def calculate_p_value(sample1, sample2)
  diff_mean = sample1.mean - sample2.mean
  pooled_std = Math.sqrt(sample1.variance / sample1.size.to_f + sample2.variance / sample2.size.to_f)
  t_stat = diff_mean / pooled_std
  p_value = (2 * (1 - Statistics2.distributions.norm.cdf(t_stat))).abs
  return p_value
end

def main
  srand(0)
  sample1 = generate_data(100)
  sample2 = generate_data(100)
  p_value = calculate_p_value(sample1, sample2)
  puts p_value
end

main