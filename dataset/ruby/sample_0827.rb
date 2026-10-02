require 'matrix'

class Activation

  def sigmoid(x)
    1.0 / (1.0 + Math.exp(-x))
  end

  def relu(x)
    [0, x].max
  end

end

class Layer

  attr_accessor :weights, :bias, :activation

  def initialize(weights, bias, activation)
    @weights = weights
    @bias = bias
    @activation = activation
  end

  def forward(input_data)
    z = input_data * @weights + @bias
    @activation.call(z)
  end

end

class NeuralNetwork

  attr_accessor :layers

  def initialize(layers)
    @layers = layers
  end

  def predict(input_data)
    @layers.each do |layer|
      input_data = layer.forward(input_data)
    end
    input_data
  end

end

def initialize_network(layer_sizes, activation_type)
  activation = Activation.new
  layers = []
  (0...layer_sizes.length - 1).each do |i|
    weights = Matrix.build(layer_sizes[i], layer_sizes[i + 1]) { rand }
    bias = Vector.build(layer_sizes[i + 1]) { rand }
    if activation_type == 'sigmoid'
      layers << Layer.new(weights, bias, method(:sigmoid))
    elsif activation_type == 'relu'
      layers << Layer.new(weights, bias, method(:relu))
    end
  end
  NeuralNetwork.new(layers)
end

def main
  input_data = Matrix.rows([[0, 0], [0, 1], [1, 0], [1, 1]])
  expected_output = Matrix.rows([[0], [1], [1], [0]])
  network = initialize_network([2, 4, 1], 'sigmoid')
  output = network.predict(input_data)
  puts output
end

main