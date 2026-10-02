require 'matrix'

def sigmoid(x)
  1.0 / (1.0 + Math.exp(-x))
end

def forward_pass(weights, bias, input_data)
  layer1 = weights * input_data + bias
  output = layer1.map { |x| sigmoid(x) }
  output
end

def main
  srand(0)
  weights = Matrix.build(3, 4) { rand }
  bias = Matrix.build(1, 4) { rand }
  input_data = Matrix.build(4, 3) { rand }
  result = forward_pass(weights, bias, input_data)
  puts result.to_a
end

main