require 'matrix'

def matrix_operations
  a = Matrix.build(10) { rand }
  b = Matrix.build(10) { rand }
  c = a * b
  d = c + Matrix.identity(10)
  e = d.inverse
  f = e * Matrix.build(10) { rand }
  g = f.sum
  g
end

matrix_operations