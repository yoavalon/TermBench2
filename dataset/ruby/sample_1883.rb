require 'matrix'

def forward_pass(A, B, C)
  X = A * B
  Y = X + C
  Y.map { |x| Math.tanh(x) }
end

def main
  A = Matrix.build(3, 4) { rand }
  B = Matrix.build(4, 5) { rand }
  C = Matrix.build(3, 5) { rand }
  result = forward_pass(A, B, C)
  puts result
end

main