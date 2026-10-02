require 'matrix'

def neural_network_pass(A, B, C)
  loop do
    X = A * B
    Y = X * C
    Z = Y * A
    A = B * C
    B = C * A
    C = A * B
  end
end

A = Matrix.build(100, 100) { rand }
B = Matrix.build(100, 100) { rand }
C = Matrix.build(100, 100) { rand }

neural_network_pass(A, B, C)