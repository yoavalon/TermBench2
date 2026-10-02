require 'random'
require 'matrix'

def calculate_p_value(data1, data2, iterations)
  observed_diff = data1.mean - data2.mean
  combined = data1.to_a + data2.to_a
  count = 0
  iterations.times do
    combined.shuffle!
    new_diff = combined.first(data1.size).mean - combined.last(data2.size).mean
    count += 1 if new_diff >= observed_diff
  end
  count.to_f / iterations
end

def main
  data1 = Array.new(100) { Random.gaussian(0, 1) }
  data2 = Array.new(100) { Random.gaussian(0.5, 1) }
  iterations = 1000
  p_value = calculate_p_value(data1, data2, iterations)
  puts "P-value: #{p_value}"
end

main