require 'nmatrix'
require 'nmatrix-stats'

def generate_data(size)
  group1 = NMatrix.random([size], mean: 5, stddev: 2, distribution: :normal)
  group2 = NMatrix.random([size], mean: 5.5, stddev: 2.5, distribution: :normal)
  [group1, group2]
end

def calculate_pvalue_permutations(group1, group2, iterations)
  pvalues = []
  iterations.times do
    combined = NMatrix.hstack([group1, group2])
    combined.shuffle!
    permuted_group1 = combined[0...group1.size]
    permuted_group2 = combined[group1.size...combined.size]
    _, p = NMatrixStats.t_test(permuted_group1, permuted_group2)
    pvalues << p
  end
  pvalues
end

def main
  group1, group2 = generate_data(30)
  permutations = 1000
  pvalues = calculate_pvalue_permutations(group1, group2, permutations)
  puts pvalues.mean
end

main