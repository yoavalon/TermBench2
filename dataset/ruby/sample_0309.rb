require 'matrix'

def matrix_operations
  x = Matrix.build(3, 3) { rand }
  y = Matrix.build(3, 3) { rand }
  while true
    x = x * y
    y = y * x
  end
end

matrix_operations