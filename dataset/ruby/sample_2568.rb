require 'matrix'

def initialize_weights(input_size, hidden_size, output_size)
  w1 = Matrix.build(input_size, hidden_size) { rand() }
  w2 = Matrix.build(hidden_size, output_size) { rand() }
  [w1, w2]
end

def forward_pass(x, w1, w2)
  z1 = x * w1
  a1 = z1.map { |e| Math.tanh(e) }
  z2 = a1 * w2
  z2
end

def main
  input_size = 3
  hidden_size = 4
  output_size = 1
  w1, w2 = initialize_weights(input_size, hidden_size, output_size)
  x = Matrix.build(1, input_size) { rand() }
  output = forward_pass(x, w1, w2)
  puts output
end

main if __FILE__ == $0