require 'matrix'

class MatrixProcessor
  def initialize(data)
    @data = data
    @processed_data = nil
  end

  def normalize
    mean = @data.mean
    std = @data.std
    @processed_data = (@data - mean) / std
  end

  def apply_weight(weights)
    @processed_data = @processed_data * weights
  end

  def activate
    @processed_data = @processed_data.map { |x| x > 0 ? x : 0 }
  end
end

class NeuralNetwork
  def initialize(layers)
    @layers = layers
    @weights = (0...layers.length - 1).map { Matrix.build(layers[_1], layers[_2]) { rand } }
  end

  def forward_pass(data)
    processor = MatrixProcessor.new(data)
    @weights.each_with_index do |weight, i|
      processor.normalize
      processor.apply_weight(weight)
      processor.activate
    end
    processor.processed_data
  end
end

def main
  data = Matrix.build(10, 5) { rand }
  layers = [5, 10, 5]
  network = NeuralNetwork.new(layers)
  output = network.forward_pass(data)
  puts output.to_a
end

main if __FILE__ == $0