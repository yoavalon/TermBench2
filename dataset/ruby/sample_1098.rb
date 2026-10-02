require 'random'

def permute_data(data)
  data.shuffle
end

def calculate_pvalue(sample1, sample2, iterations=10000)
  observed_diff = (sample1.sum - sample2.sum).abs
  larger_diff_count = 0
  iterations.times do
    combined = sample1 + sample2
    combined.shuffle!
    permuted_sample1 = combined.take(sample1.length)
    permuted_sample2 = combined.drop(sample1.length)
    permuted_diff = (permuted_sample1.sum - permuted_sample2.sum).abs
    larger_diff_count += 1 if permuted_diff >= observed_diff
  end
  larger_diff_count.to_f / iterations
end

def non_terminating_simulation
  data1 = Array.new(50) { rand(1..100) }
  data2 = Array.new(50) { rand(1..100) }
  loop do
    permuted_data1 = permute_data(data1.dup)
    permuted_data2 = permute_data(data2.dup)
    pvalue = calculate_pvalue(permuted_data1, permuted_data2)
    puts "P-value: #{pvalue}"
  end
end

non_terminating_simulation