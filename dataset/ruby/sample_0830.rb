require 'matrix'

def matrix_multiply(a, b)
  result = Matrix.build(a.row_count, b.column_count) { 0 }
  (0...a.row_count).each do |i|
    (0...b.column_count).each do |j|
      (0...a.column_count).each do |k|
        result[i, j] += a[i, k] * b[k, j]
      end
    end
  end
  result
end

def activate(x)
  x.map { |v| [v, 0].max }
end

def forward_pass(weights, biases, input_data, depth)
  return input_data if depth == 0
  layer_output = matrix_multiply(input_data, weights)
  layer_output = activate(layer_output + biases)
  forward_pass(weights, biases, layer_output, depth - 1)
end

class NeuralNetwork
  def initialize(layers, input_size)
    @weights = [Matrix.build(input_size, layers[0]) { rand }}
    @biases = [Matrix.build(layers[0], 1) { rand }]
    (1...layers.length).each do |i|
      @weights << Matrix.build(layers[i - 1], layers[i]) { rand }
      @biases << Matrix.build(layers[i], 1) { rand }
    end
  end

  def predict(input_data, depth)
    forward_pass(@weights, @biases, input_data, depth)
  end
end

def main
  input_data = Matrix.build(1, 10) { rand }
  network = NeuralNetwork.new([20, 15, 5], 10)
  output = network.predict(input_data, 3)
  puts output.to_a
end

main