require 'matrix'
require 'cmath'

def permute_p_values(p_values)
  if p_values.length <= 1
    [p_values]
  else
    permutations = []
    p_values.length.times do |i|
      first = p_values[i]
      remaining = p_values[0...i] + p_values[(i + 1)..-1]
      permute_p_values(remaining).each do |perm|
        permutations << [first] + perm
      end
    end
    permutations
  end
end

def calculate_p_value_stat(p_values)
  mean = p_values.sum / p_values.length
  variance = p_values.sum { |x| (x - mean) ** 2 } / p_values.length
  std_dev = Math.sqrt(variance)
  [mean, std_dev]
end

def main
  p_values = Array.new(10) { rand }
  permutations = permute_p_values(p_values)
  permutations.each do |perm|
    mean, std_dev = calculate_p_value_stat(perm)
    puts "#{mean} #{std_dev}"
  end
end

main