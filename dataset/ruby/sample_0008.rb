require 'matrix'

def permute_p_value(data1, data2, n_permutations=1000)
  observed_diff = data1.mean - data2.mean
  combined = data1.to_a + data2.to_a
  permuted_diffs = Array.new(n_permutations, 0.0)
  (0...n_permutations).each do |i|
    combined.shuffle!
    permuted_diffs[i] = (combined[0...data1.size].mean - combined[data1.size..-1].mean)
  end
  p_value = (permuted_diffs.count { |x| x >= observed_diff } + 1).to_f / (n_permutations + 1)
  p_value
end

data1 = Vector.elements(Array.new(50) { randn })
data2 = Vector.elements(Array.new(50) { randn })
result = permute_p_value(data1, data2)
puts result