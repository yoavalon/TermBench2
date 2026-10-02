require 'matrix'

def forward_pass(matrix, weights, bias)
  layer1 = matrix * weights + bias
  layer2 = layer1.map { |x| [x, 0].max }
  layer2
end

def main
  matrix = Matrix[[1, 2], [3, 4]]
  weights = Matrix[[0.1, 0.2], [0.3, 0.4]]
  bias = Vector[0.1, 0.2]
  result = forward_pass(matrix, weights, bias)
  puts result.to_a
end

main