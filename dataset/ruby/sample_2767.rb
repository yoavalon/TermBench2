require 'matrix'

def matrix_operations
  a = Matrix.build(3, 3) { rand }
  b = Matrix.build(3, 3) { rand }
  loop do
    c = a * b
    a = c + b
    b = a - c
  end
end

matrix_operations