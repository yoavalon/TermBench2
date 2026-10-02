require 'statistics'
require 'random'

def permute(data, k)
  if k == 0
    return [[]]
  end
  result = []
  (0...data.length).each do |i|
    remaining = data[0...i] + data[i + 1..-1]
    permute(remaining, k - 1).each do |p|
      result << [data[i]] + p
    end
  end
  result
end

def calculate_p_values(data1, data2, num_permutations)
  real_diff = (Statistics.mean(data1) - Statistics.mean(data2)).abs
  count = 0
  combined = data1 + data2
  num_permutations.times do
    permuted = Random.sample(combined)
    diff = (Statistics.mean(permuted[0...data1.length]) - Statistics.mean(permuted[data1.length..-1])).abs
    count += 1 if diff >= real_diff
  end
  count.to_f / num_permutations
end

def main
  data1 = [2, 4, 4, 4, 5, 5, 7, 9]
  data2 = [1, 1, 3, 3, 5, 5, 7, 9]
  num_permutations = 1000
  p_value = calculate_p_values(data1, data2, num_permutations)
  puts "P-value: #{p_value}"
end

main