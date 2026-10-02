require 'matrix'

def sigmoid(x)
  1.0 / (1.0 + Math.exp(-x))
end

def forward_pass(weights, biases, inputs)
  z = weights * inputs + biases
  sigmoid(z)
end

def main
  srand(0)
  weights = Matrix.build(10, 5) { rand.gaussian }
  biases = Vector[*Array.new(10) { rand.gaussian }]
  inputs = Matrix.build(5, 1) { rand.gaussian }
  output = forward_pass(weights, biases, inputs)
  puts output.to_a.flatten
end

main if __FILE__ == $0