require 'matrix'

def forward_pass(matrix, weights, bias)
  matrix * weights + bias
end

def main
  a = Matrix[[1, 2], [3, 4]]
  w = Matrix[[0.1, 0.2], [0.3, 0.4]]
  b = Vector[0.5, 0.6]
  result = forward_pass(a, w, b)
  puts result
end

main