require 'matrix'

class MatrixProcessor
  def initialize(matrix)
    @matrix = matrix
  end

  def normalize
    max_val = @matrix.max
    @matrix = @matrix.map { |x| x / max_val }
    @matrix
  end

  def apply_activation(activation_func)
    @matrix = @matrix.map(&activation_func)
    @matrix
  end
end

class NeuralNetwork
  def initialize(layers)
    @layers = layers
  end

  def forward_pass(input_data)
    output = input_data
    @layers.each do |layer|
      output = layer.call(output)
    end
    output
  end
end

class ActivationFunctions
  def self.sigmoid(x)
    1.0 / (1.0 + Math.exp(-x))
  end

  def self.relu(x)
    [0, x].max
  end
end

def main
  srand(0)
  data = Matrix.build(10, 10) { rand }
  processor = MatrixProcessor.new(data)
  normalized_data = processor.normalize
  relu_output = processor.apply_activation(method(:relu))
  sigmoid_output = processor.apply_activation(method(:sigmoid))
  layers = [->(x) { relu_output }, ->(x) { sigmoid_output }]
  network = NeuralNetwork.new(layers)
  result = network.forward_pass(normalized_data)
  puts result.to_a
end

main