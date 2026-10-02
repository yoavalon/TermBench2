def recursive_filter(x, a, b)
  [recursive_filter(x[1..-1], a, b)] + [a[0] * x[0] + a[1..-1].zip(recursive_filter(x[1..-1], a, b)).map { |i, j| i * j }.sum - b[1..-1].zip(recursive_filter(x[1..-1], a, b)).map { |i, j| i * j }.sum]
end

def main
  require 'matrix'
  x = Array.new(100) { rand }
  a = Matrix[[1, -0.5]].to_a.flatten
  b = Matrix[[1, -0.3]].to_a.flatten
  recursive_filter(x, a, b)
end

main