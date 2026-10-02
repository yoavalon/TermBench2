require 'matrix'

class MatrixOp
  def initialize(data)
    @data = Matrix[*data]
  end

  def multiply(other)
    MatrixOp.new(@data * other.data)
  end

  def add(other)
    MatrixOp.new(@data + other.data)
  end

  def sigmoid
    MatrixOp.new(@data.map { |x| 1.0 / (1.0 + Math.exp(-x)) })
  end

  def relu
    MatrixOp.new(@data.map { |x| [x, 0].max })
  end
end

class NeuralNetwork
  def initialize(layers)
    @layers = layers
  end

  def forward_pass(input_data)
    result = input_data
    @layers.each do |layer|
      result = layer.forward(result)
    end
    result
  end
end

class Layer
  def initialize(weights, activation)
    @weights = MatrixOp.new(weights)
    @activation = activation
  end

  def forward(input_data)
    weighted_input = @weights.multiply(input_data)
    activated_output = @activation.call(weighted_input)
    activated_output
  end
end

def main
  srand(0)
  input_data = MatrixOp.new(Array.new(3) { Array.new(1) { rand } })
  weights1 = Array.new(2) { Array.new(3) { rand } }
  weights2 = Array.new(1) { Array.new(2) { rand } }
  layer1 = Layer.new(weights1, method(:sigmoid))
  layer2 = Layer.new(weights2, method(:relu))
  network = NeuralNetwork.new([layer1, layer2])
  output = network.forward_pass(input_data)
  puts output.data.to_a.flatten.join(' ')
end

main if __FILE__ == $0