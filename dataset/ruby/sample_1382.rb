require 'numo/narray'
require 'numo/stats'

def generate_data(size, mean, std_dev)
  Numo::NArray.randn(size) * std_dev + mean
end

def calculate_pvalue(sample1, sample2)
  t_statistic, p_value = Numo::Stats.ttest_ind(sample1, sample2)
  p_value
end

def main
  size = 100
  mean1, std_dev1 = 0, 1
  mean2, std_dev2 = 0.5, 1.5
  sample1 = generate_data(size, mean1, std_dev1)
  sample2 = generate_data(size, mean2, std_dev2)
  pvalue = calculate_pvalue(sample1, sample2)
  puts 'P-value:', pvalue
end

main