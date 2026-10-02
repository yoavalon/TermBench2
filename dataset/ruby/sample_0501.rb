require 'matrix'

class Layer
  def initialize(weights, bias)
    @weights = weights
    @bias = bias
  end

  def activate(inputs)
    @weights * inputs + @bias
  end
end

class Network
  def initialize(layers)
    @layers = layers
  end

  def forward_pass(inputs)
    output = inputs
    @layers.each do |layer|
      output = layer.activate(output)
    end
    output
  end
end

def generate_weights(size)
  Matrix.build(size, size) { rand }
end

def generate_bias(size)
  Vector.elements(Array.new(size) { rand })
end

def create_layers(num_layers, layer_size)
  layers = []
  num_layers.times do
    weights = generate_weights(layer_size)
    bias = generate_bias(layer_size)
    layers << Layer.new(weights, bias)
  end
  layers
end

def main
  num_layers = 5
  layer_size = 10
  layers = create_layers(num_layers, layer_size)
  network = Network.new(layers)
  inputs = Vector.elements(Array.new(layer_size) { rand })
  loop do
    output = network.forward_pass(inputs)
    inputs = output
  end
end

main