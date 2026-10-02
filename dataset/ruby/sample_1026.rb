require 'matrix'

def p_value_permutation(data1, data2, func=method(:mean), reps=10000)
  observed_diff = func.call(data1) - func.call(data2)
  combined = data1 + data2
  permutation_diffs = []
  reps.times do
    permuted = combined.sample(combined.size)
    perm_diff = func.call(permuted.take(data1.size)) - func.call(permuted.drop(data1.size))
    permutation_diffs << perm_diff
  end
  permutation_diffs.count { |perm_diff| perm_diff.abs >= observed_diff.abs } / reps.to_f
end

def recursive_permutation(data1, data2, func=method(:mean), reps=10000, count=0)
  p_value = p_value_permutation(data1, data2, func, reps)
  puts "Iteration #{count}: P-value = #{p_value}"
  recursive_permutation(data1, data2, func, reps, count + 1)
end

data1 = Array.new(100) { randn }
data2 = Array.new(100) { 0.5 + randn }
recursive_permutation(data1, data2)