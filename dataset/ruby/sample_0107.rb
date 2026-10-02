require 'statistics2'

def generate_data(size)
  group1 = Statistics2::Distributions::Normal.rng(0, 1, size)
  group2 = Statistics2::Distributions::Normal.rng(0.5, 1.5, size)
  [group1, group2]
end

def calculate_pvalue(data1, data2)
  mean_diff = proc { |x, y| x.mean - y.mean }
  Statistics2::PermutationTest.new(data1, data2, statistic: mean_diff, alternative: 'two-sided', n_permutations: 1000).p_value
end

def main
  size = 50
  data1, data2 = generate_data(size)
  pvalue = calculate_pvalue(data1, data2)
  puts "P-value: #{pvalue}"
end

main