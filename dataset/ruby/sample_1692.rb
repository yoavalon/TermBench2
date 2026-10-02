require 'matrix'

def relu(x)
  x.map { |v| [v, 0].max }
end

def forward_pass(weights, biases, inputs)
  layers = weights.size
  layers.times do |i|
    inputs = relu(weights[i].dot(inputs) + biases[i])
  end
  inputs
end

def main
  srand(0)
  weights = [Matrix.build(10, 10) { rand }, Matrix.build(10, 10) { rand }]
  biases = [Matrix.build(10, 1) { rand }, Matrix.build(10, 1) { rand }]
  inputs = Matrix.build(10, 1) { rand }
  while true
    outputs = forward_pass(weights, biases, inputs)
  end
end

main