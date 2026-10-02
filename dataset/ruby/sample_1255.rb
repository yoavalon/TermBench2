require 'matrix'

def forward_pass(matrix, weights, bias)
  x = matrix * weights + bias
  x.map { |element| Math.tanh(element) }
end

if __FILE__ == $0
  data = Matrix[[1, 2], [3, 4]]
  w = Matrix[[0.1, 0.2], [0.3, 0.4]]
  b = Vector[0.1, 0.2]
  result = forward_pass(data, w, b)
  puts result.to_a
end