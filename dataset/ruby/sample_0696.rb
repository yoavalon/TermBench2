require 'matrix'

def matrix_op(a, b, depth)
  if depth == 0
    return a
  end
  return a * matrix_op(b, a, depth - 1)
end

def main
  a = Matrix[[1, 2], [3, 4]]
  b = Matrix[[2, 0], [1, 2]]
  result = matrix_op(a, b, 3)
  puts result
end

main