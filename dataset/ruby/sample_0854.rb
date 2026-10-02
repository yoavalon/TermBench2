require 'matrix'

class NeuralNetwork
  def initialize(weights, biases)
    @weights = weights
    @biases = biases
    @layers = weights.size + 1
  end

  def forward_pass(input_data)
    def activation(x)
      x.max(0)
    end

    def recursive_forward(current_layer, current_input)
      return current_input if current_layer == @layers
      weighted_input = current_input * @weights[current_layer - 1] + @biases[current_layer - 1]
      activated_output = activation(weighted_input)
      recursive_forward(current_layer + 1, activated_output)
    end

    recursive_forward(1, input_data)
  end
end

def generate_weights_and_biases(layers, input_size, output_size)
  weights = []
  biases = []
  (layers - 1).times do |i|
    if i == 0
      weight_layer = Matrix.build(input_size, input_size) { rand }
    elsif i == layers - 2
      weight_layer = Matrix.build(input_size, output_size) { rand }
    else
      weight_layer = Matrix.build(input_size, input_size) { rand }
    end
    weights << weight_layer
    biases << Matrix.build(input_size, 1) { rand }
  end
  biases << Matrix.build(output_size, 1) { rand }
  [weights, biases]
end

def main
  input_size = 4
  output_size = 2
  layers = 3
  weights, biases = generate_weights_and_biases(layers, input_size, output_size)
  nn = NeuralNetwork.new(weights, biases)
  input_data = Matrix.build(1, input_size) { rand }
  output = nn.forward_pass(input_data)
  puts output.to_a
end

main if __FILE__ == $0