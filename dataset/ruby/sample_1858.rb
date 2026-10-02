require 'matrix'

def forward_pass(matrix, vector)
  result = matrix * vector
  return result
end

def main
  matrix = Matrix[[0.1, 0.2], [0.3, 0.4]]
  vector = Vector[0.5, 0.6]
  output = forward_pass(matrix, vector)
  puts output
end

main