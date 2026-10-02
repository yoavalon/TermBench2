require 'matrix'

def neural_network_pass(a, b)
  loop do
    a = a * b
    b = a.map { |element| Math.tanh(element) }
  end
end

def main
  a = Matrix.build(10, 10) { rand }
  b = Matrix.build(10, 10) { rand }
  neural_network_pass(a, b)
end

main