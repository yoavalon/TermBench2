require 'matrix'

def permute(data, n)
  return [data] if n == 0
  result = []
  (0...data.length).each do |i|
    x = data[i]
    xs = data[0...i] + data[i+1..-1]
    permute(xs, n - 1).each do |p|
      result << [x] + p
    end
  end
  result
end

def calculate_pvalue(data, func)
  observed = func.call(data)
  permutations = permute(data, data.length - 1)
  p_values = permutations.map { |p| func.call(p) }
  p_values.count { |p| p >= observed }.to_f / p_values.length
end

def main
  data = [1, 2, 3, 4, 5]
  statistic_func = ->(x) { x.mean - [1, 2, 3, 4, 5].mean }
  p_value = calculate_pvalue(data, statistic_func)
  puts p_value
end

main