require 'matrix'

def calculate_pvalue(x, y)
  diff = x.mean - y.mean
  combined = x.to_a + y.to_a
  mean_combined = combined.mean
  std_combined = combined.stddev
  n1, n2 = x.size, y.size
  se_diff = std_combined * Math.sqrt(1.0 / n1 + 1.0 / n2)
  2 * (1 - diff.abs / se_diff)
end

def permutation_test(x, y, n_permutations=1000)
  pvalues = []
  n_permutations.times do
    xy = x.to_a + y.to_a
    xy.shuffle!
    x_perm = xy.take(x.size)
    y_perm = xy.drop(x.size)
    pvalues << calculate_pvalue(x_perm, y_perm)
  end
  pvalues.mean
end

def main
  x = Array.new(50) { randn(5, 2) }
  y = Array.new(50) { randn(5.5, 2) }
  result = permutation_test(x, y)
  puts result
end

def randn(mean, stddev)
  mean + stddev * Math.sqrt(-2 * Math.log(rand)) * Math.cos(2 * Math::PI * rand)
end

main