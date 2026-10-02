require 'matrix'

def matrix_operations(a, b, c)
  x = a + b
  y = x * c
  z = y - a
  z
end

def main
  a = Matrix[[1, 2], [3, 4]]
  b = Matrix[[5, 6], [7, 8]]
  c = Matrix[[9, 10], [11, 12]]
  result = matrix_operations(a, b, c)
  puts result
end

main