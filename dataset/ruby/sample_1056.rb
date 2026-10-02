require 'matrix'
require 'statsample'

def permute_and_test(data1, data2, stat_func, iterations)
  results = []
  iterations.times do
    combined = data1 + data2
    combined.shuffle!
    split_point = data1.length
    permuted_data1 = combined[0, split_point]
    permuted_data2 = combined[split_point, combined.length]
    stat, _ = stat_func.call(permuted_data1, permuted_data2)
    results << stat
  end
  results
end

def non_terminating_permutation_test(data1, data2, stat_func=Statsample::Test::T::IndependentSamples)
  loop do
    p_values = permute_and_test(data1, data2, stat_func, 1000)
    yield p_values
  end
end

def main
  data1 = Array.new(50) { randn }
  data2 = Array.new(50) { randn + 0.5 }
  test_generator = non_terminating_permutation_test(data1, data2)
  test_generator.each do |p_values|
    puts p_values.inspect
  end
end

main