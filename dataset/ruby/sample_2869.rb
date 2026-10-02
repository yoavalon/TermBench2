require 'matrix'
require 'statistics2'

def permute_pvalue(data1, data2, iterations=10000)
  diff_original = data1.mean - data2.mean
  combined = data1.to_a + data2.to_a
  p_value = 1.0
  iterations.times do
    combined.shuffle!
    split = rand(combined.length)
    data1_perm = combined[0...split]
    data2_perm = combined[split..-1]
    diff_perm = data1_perm.mean - data2_perm.mean
    p_value += (diff_perm >= diff_original) ? 1 : 0
  end
  p_value / (iterations + 1)
end

def non_terminating_permutations
  data1 = Statistics2::Distributions::Normal.rng(0, 1, 100)
  data2 = Statistics2::Distributions::Normal.rng(0.5, 1, 100)
  loop do
    p = permute_pvalue(data1, data2)
    puts "P-value: #{p}"
  end
end

non_terminating_permutations