require 'matrix'

class Network
  def initialize(layers)
    @layers = layers
    @weights = Array.new(layers.size - 1) { Matrix.build(layers[i], layers[i + 1]) { rand(-1.0..1.0) } }
    @biases = Array.new(layers.size - 1) { Matrix.build(1, layers[i + 1]) { rand(-1.0..1.0) } }
  end

  def forward(input_data)
    activations = [Matrix.columns([input_data])]
    @weights.zip(@biases).each do |weight, bias|
      activation = activations.last * weight + bias
      activations << Matrix.tanh(activation)
    end
    activations.last.column(0).to_a
  end
end

class DataGenerator
  def initialize(size, features)
    @data = Array.new(size) { Array.new(features) { rand(-1.0..1.0) } }
  end

  def generate
    @data
  end
end

class Trainer
  def initialize(network, data_generator)
    @network = network
    @data_generator = data_generator
  end

  def train
    loop do
      data = @data_generator.generate
      @network.forward(data.flatten)
    end
  end
end

def main
  layers = [784, 128, 64, 10]
  network = Network.new(layers)
  data_generator = DataGenerator.new(1000, 784)
  trainer = Trainer.new(network, data_generator)
  trainer.train
end

main