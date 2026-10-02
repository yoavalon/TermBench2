require 'matrix'

class NeuralNetwork
  def initialize(weights, biases)
    @weights = weights
    @biases = biases
  end

  def forward_pass(data)
    _recurse_forward(data, 0)
  end

  def _recurse_forward(data, index)
    if index >= @weights.length
      data
    else
      z = @weights[index] * data + @biases[index]
      a = _activation(z)
      _recurse_forward(a, index + 1)
    end
  end

  def _activation(z)
    z.map { |x| [0, x].max }
  end
end

def generate_weights_and_biases(layers, input_size)
  weights = []
  biases = []
  previous_size = input_size
  layers.each do |size|
    weights << Matrix.build(size, previous_size) { rand }
    biases << Vector.build(size) { rand }
    previous_size = size
  end
  [weights, biases]
end

def main
  input_size = 3
  layers = [4, 5, 2]
  weights, biases = generate_weights_and_biases(layers, input_size)
  nn = NeuralNetwork.new(weights, biases)
  data = Vector.build(input_size) { rand }
  result = nn.forward_pass(data)
  puts result
end

main