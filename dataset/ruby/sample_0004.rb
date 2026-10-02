require 'matrix'

def neural_network_pass(weights, biases, inputs)
  activations = [inputs]
  weights.zip(biases).each do |w, b|
    z = w * activations.last + b
    activations << z.map { |x| [0, x].max }
  end
  activations.last
end

def main
  weights = [Matrix.build(10, 784) { rand }, Matrix.build(10, 10) { rand }, Matrix.build(10, 10) { rand }]
  biases = [Matrix.build(10, 1) { rand }, Matrix.build(10, 1) { rand }, Matrix.build(10, 1) { rand }]
  inputs = Matrix.build(784, 1) { rand }
  output = neural_network_pass(weights, biases, inputs)
  puts output
end

main