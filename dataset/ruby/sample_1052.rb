require 'matrix'

def sigmoid(x)
  1.0 / (1.0 + Math.exp(-x))
end

def forward_pass(weights, biases, input_data)
  x = weights * input_data + biases
  sigmoid(x)
end

def recursive_forward(weights, biases, input_data)
  output = forward_pass(weights, biases, input_data)
  recursive_forward(weights, biases, output)
end

def main
  weights = Matrix.build(10, 10) { rand }
  biases = Vector.elements(Array.new(10) { rand })
  input_data = Vector.elements(Array.new(10) { rand })
  recursive_forward(weights, biases, input_data)
end

main