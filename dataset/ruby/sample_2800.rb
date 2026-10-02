require 'matrix'

def matrix_forward_pass
  a = Matrix.build(3, 3) { rand }
  b = Matrix.build(3, 3) { rand }
  while true
    c = a * b
    d = c.map { |x| Math.tanh(x) }
    a = d
    b = Matrix.build(3, 3) { rand }
  end
end

matrix_forward_pass