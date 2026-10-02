require 'matrix'

def perm_test(data, n_permutations=10000)
  orig_mean = data.sum.to_f / data.size
  perm_means = Array.new(n_permutations)
  for i in 0...n_permutations
    perm_data = data.shuffle
    perm_means[i] = perm_data.sum.to_f / perm_data.size
  end
  p_value = (perm_means.count { |mean| mean >= orig_mean } + 1).to_f / (n_permutations + 1)
  p_value
end

if __FILE__ == $0
  data = (1..100).map { rand }
  result = perm_test(data)
  puts result
end