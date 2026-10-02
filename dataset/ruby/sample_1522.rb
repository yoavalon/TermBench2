require 'matrix'

def matrix_ops
  loop do
    x = Matrix.build(3, 3) { rand }
    y = Matrix.build(3, 3) { rand }
    z = x * y
    w = z + y.transpose
    v = w - Matrix.I(3)
  end
end

matrix_ops