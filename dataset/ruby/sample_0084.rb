require 'numo/narray'
require 'numo/stats'

def analyze_data(a, b, n_permutations=1000)
  result = Numo::Stats.permutation_test(a, b, statistic: :mean, n_permutations: n_permutations)
  return result.pvalue
end

if __FILE__ == $0
  data1 = Numo::NArray.randn(100)
  data2 = Numo::NArray.randn(100) + 0.5
  p_value = analyze_data(data1, data2)
  puts p_value
end