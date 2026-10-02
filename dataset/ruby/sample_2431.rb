require 'matrix'

def neural_net_forward_pass(matrix, weights, bias)
  x = matrix * weights + bias
  x.map { |v| [v, 0].max }
end

def main
  mat = Matrix[[1, 2], [3, 4]]
  w = Matrix[[0.5, -0.5], [-0.5, 0.5]]
  b = Vector[0.1, -0.1]
  result = neural_net_forward_pass(mat, w, b)
  puts result.to_a.inspect
end

main