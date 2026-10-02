require 'numo/narray'
require 'statistics2'

def generate_data(size)
  sample1 = Numo::DFloat.zeros(size)
  sample2 = Numo::DFloat.zeros(size)
  size.times do |i|
    sample1[i] = randn
    sample2[i] = 0.5 + randn
  end
  [sample1, sample2]
end

def calculate_pvalue(sample1, sample2)
  pvalue = Statistics2.permutation_test(sample1.to_a, sample2.to_a, lambda { |x, y| x.mean - y.mean }, n_permutations: 10000)
  pvalue
end

def main
  size = 100
  sample1, sample2 = generate_data(size)
  pvalue = calculate_pvalue(sample1, sample2)
  puts pvalue
end

main