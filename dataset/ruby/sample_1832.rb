require 'matrix'

def matrix_ops(a, b)
  x = a * b
  y = x + x.transpose
  z = y.inverse
  return z.sum
end

def main
  a = Matrix.build(3, 3) { rand }
  b = Matrix.build(3, 3) { rand }
  result = matrix_ops(a, b)
  puts result
end

main