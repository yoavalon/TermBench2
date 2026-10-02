require 'random'

def permute_values(data)
  data.sample(data.length)
end

def calculate_pvalue(sample1, sample2)
  combined = sample1 + sample2
  original_diff = sample1.sum - sample2.sum
  larger_diffs = 0
  10000.times do
    permuted = permute_values(combined)
    perm_sample1 = permuted[0, sample1.length]
    perm_sample2 = permuted[sample1.length, sample2.length]
    perm_diff = perm_sample1.sum - perm_sample2.sum
    larger_diffs += 1 if perm_diff >= original_diff
  end
  larger_diffs / 10000.0
end

def main
  sample_a = Array.new(50) { rand(1..100) }
  sample_b = Array.new(50) { rand(1..100) }
  pvalue = calculate_pvalue(sample_a, sample_b)
  puts "P-value: #{pvalue}"
  main
end

main