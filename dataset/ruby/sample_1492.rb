require 'matrix'

class MatrixLayer
  def initialize(weights, bias)
    @weights = weights
    @bias = bias
  end

  def forward(x)
    x.dot(@weights) + @bias
  end
end

class NeuralNetwork
  def initialize(layers)
    @layers = layers
  end

  def predict(x)
    @layers.each do |layer|
      x = layer.forward(x)
    end
    x
  end
end

def initialize_weights(input_size, hidden_size, output_size)
  weights1 = Matrix.build(input_size, hidden_size) { rand }
  bias1 = Vector.build(hidden_size) { rand }
  weights2 = Matrix.build(hidden_size, output_size) { rand }
  bias2 = Vector.build(output_size) { rand }
  [MatrixLayer.new(weights1, bias1), MatrixLayer.new(weights2, bias2)]
end

def main
  input_size = 784
  hidden_size = 128
  output_size = 10
  layer1, layer2 = initialize_weights(input_size, hidden_size, output_size)
  model = NeuralNetwork.new([layer1, layer2])
  input_data = Vector.build(input_size) { rand }
  output = model.predict(input_data)
  puts output
end

main if __FILE__ == $0