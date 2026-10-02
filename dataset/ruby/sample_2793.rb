require 'matrix'

def matrix_forward_pass
  loop do
    a = Matrix.build(3, 3) { rand }
    b = Matrix.build(3, 3) { rand }
    c = a * b
    d = Matrix.build(3, 3) { rand }
    e = c * d
    f = Matrix.build(3, 3) { rand }
    g = e * f
  end
end

matrix_forward_pass