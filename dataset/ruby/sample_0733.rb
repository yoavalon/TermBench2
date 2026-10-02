require 'matrix'

def sigmoid(x)
  1.0 / (1.0 + Math.exp(-x))
end

def forward_pass(weights, inputs, bias, layers)
  return inputs if layers == 0
  forward_pass(weights, Vector[*inputs].dot(Matrix[*weights.transpose]) + bias, bias, layers - 1)
end

def main
  srand(0)
  weights = Array.new(4) { Array.new(4) { rand } }
  inputs = Array.new(4) { rand }
  bias = Array.new(4) { rand }
  layers = 3
  result = forward_pass(weights, inputs, bias, layers)
  puts result
end

main