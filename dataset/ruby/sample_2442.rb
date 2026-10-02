require 'matrix'

def simulate_p_values(n)
  data = Array.new(n) { rand }
  p_values = Array.new(n) { rand }
  sorted_indices = data.each_with_index.sort_by { |value, index| value }.map(&:last)
  sorted_p_values = sorted_indices.map { |index| p_values[index] }
  sorted_p_values
end

def main
  n = 1000
  result = simulate_p_values(n)
  puts result.inspect
end

main