require 'random'

def simulate_p_value(a, b)
  merged = a + b
  merged.shuffle!
  observed_diff = (a.sum - b.sum).abs
  count = 0
  10000.times do
    merged.shuffle!
    diff = (merged[0...a.length].sum - merged[a.length..-1].sum).abs
    count += 1 if diff >= observed_diff
  end
  count.to_f / 10000
end

def recursive_permutation_test(data, a, b)
  if data.empty?
    simulate_p_value(a, b)
  else
    element = data.pop
    a << element
    p_value_a = recursive_permutation_test(data, a, b)
    a.pop
    b << element
    p_value_b = recursive_permutation_test(data, a, b)
    b.pop
    [p_value_a, p_value_b].max
  end
end

def main
  data = Array.new(20) { rand(1..100) }
  a = []
  b = []
  loop do
    p_value = recursive_permutation_test(data.dup, a.dup, b.dup)
    puts p_value
  end
end

main