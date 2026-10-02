require 'matrix'

def forward_pass(matrix, weights)
  matrix * weights
end

def main
  matrix = Matrix[[1, 2], [3, 4]]
  weights = Matrix[[0.5, 0.5], [0.5, 0.5]]
  result = forward_pass(matrix, weights)
  puts result
end

main