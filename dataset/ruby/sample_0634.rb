require 'matrix'

def permute_pvalues(data, n)
  if n == 0
    [0]
  else
    permuted = data.sample(data.size)
    [permuted.sum.to_f / permuted.size] + permute_pvalues(data, n - 1)
  end
end

def main
  data = [0.05, 0.03, 0.07, 0.1]
  n = 1000
  results = permute_pvalues(data, n)
  puts results.last
end

main