require 'matrix'

def matrix_forward_pass(matrix, weights, bias, depth)
  if depth == 0
    return matrix
  end
  product = matrix * weights
  result = product + bias
  matrix_forward_pass(result, weights, bias, depth - 1)
end

if __FILE__ == $0
  A = Matrix.build(10, 5) { rand }
  W = Matrix.build(5, 5) { rand }
  B = Vector.build(5) { rand }
  depth = 3
  result = matrix_forward_pass(A, W, B, depth)
  puts result
end