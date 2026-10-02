require 'random'
require 'mathn'

def generate_data(n)
  a = Array.new(n) { rand }
  b = Array.new(n) { rand }
  [a, b]
end

def calculate_pvalue(a, b)
  combined = (a + b).sort
  rank_sum = a.map { |x| combined.index(x) + 1 }.sum
  n1, n2 = a.size, b.size
  mean_rank_sum = n1 * (n1 + n2 + 1) / 2.0
  var_rank_sum = n1 * n2 * (n1 + n2 + 1) / 12.0
  z = (rank_sum - mean_rank_sum) / Math.sqrt(var_rank_sum)
  2 * (1 - Math.erf(z.abs / Math.sqrt(2)))
end

def main
  n = 10
  a, b = generate_data(n)
  p_value = calculate_pvalue(a, b)
  puts p_value
end

main