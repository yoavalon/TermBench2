require 'matrix'

class MatrixOperations
  def initialize(data)
    @data = Matrix[*data]
  end

  def forward_pass(weights)
    @data * Matrix[*weights]
  end

  def activation_function(x)
    x.map { |element| [element, 0].max }
  end

  def process(weights)
    intermediate = forward_pass(weights)
    activation_function(intermediate.to_a)
  end
end

class NeuralNetwork
  def initialize(layers)
    @layers = layers
  end

  def predict(input_data)
    result = Matrix[*input_data]
    @layers.each do |layer|
      result = Matrix[*layer.process(result.to_a)]
    end
    result.to_a
  end
end

def generate_random_data(shape)
  Array.new(shape[0]) { Array.new(shape[1]) { rand } }
end

def main
  input_shape = [10, 5]
  weight_shape = [5, 3]
  num_layers = 3
  input_data = generate_random_data(input_shape)
  weights = generate_random_data(weight_shape)
  layers = Array.new(num_layers) { MatrixOperations.new(generate_random_data(weight_shape)) }
  nn = NeuralNetwork.new(layers)
  output = nn.predict(input_data)
  puts output.inspect
end

main if __FILE__ == $0