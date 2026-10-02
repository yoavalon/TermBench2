require 'matrix'

def initialize_weights(input_size, hidden_size, output_size)
  W1 = Matrix.build(input_size, hidden_size) { rand }
  W2 = Matrix.build(hidden_size, output_size) { rand }
  [W1, W2]
end

def forward_pass(X, W1, W2)
  Z1 = X * W1
  A1 = Z1.map { |e| Math.tanh(e) }
  Z2 = A1 * W2
  A2 = Z2.map { |e| 1 / (1 + Math.exp(-e)) }
  A2
end

def main
  X = Matrix.build(10, 5) { rand }
  W1, W2 = initialize_weights(5, 10, 1)
  output = forward_pass(X, W1, W2)
  puts output
end

main if __FILE__ == $0