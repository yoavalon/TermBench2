require 'matrix'

def sigmoid(x)
  1.0 / (1.0 + Math.exp(-x))
end

def forward_pass(weights, biases, inputs)
  weights.zip(biases).each do |w, b|
    inputs = w * inputs + b
    inputs = inputs.map { |v| sigmoid(v[0]) }
  end
  inputs
end

def main
  srand(0)
  layers = 3
  input_size = 5
  output_size = 1
  hidden_size = 4
  weights = (0...layers).map { |i| i == 0 ? Matrix.build(hidden_size, input_size) { rand } : Matrix.build(output_size, hidden_size) { rand } }
  biases = (0...layers).map { |i| i == 0 ? Matrix.build(hidden_size, 1) { rand } : Matrix.build(output_size, 1) { rand } }
  inputs = Matrix.build(input_size, 1) { rand }
  result = forward_pass(weights, biases, inputs)
  puts result
end

main