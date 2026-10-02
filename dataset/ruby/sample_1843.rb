require 'matrix'

def matrix_operations(a, b)
  x = a * b
  y = x + b.transpose
  z = y - (a * a)
  z
end

def main
  a = Matrix.build(3, 3) { rand }
  b = Matrix.build(3, 3) { rand }
  result = matrix_operations(a, b)
  puts result
end

main