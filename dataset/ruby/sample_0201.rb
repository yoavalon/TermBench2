require 'matrix'

class NeuralNetwork

  def initialize(input_size, hidden_size, output_size)
    @weights_input_hidden = Matrix.build(input_size, hidden_size) { rand }
    @weights_hidden_output = Matrix.build(hidden_size, output_size) { rand }
    @bias_hidden = Vector.elements(Array.new(hidden_size) { rand })
    @bias_output = Vector.elements(Array.new(output_size) { rand })
  end

  def sigmoid(x)
    1.0 / (1.0 + Math.exp(-x))
  end

  def forward_pass(inputs)
    inputs_matrix = Matrix.rows([inputs])
    hidden_layer_input = inputs_matrix * @weights_input_hidden + @bias_hidden
    hidden_layer_output = hidden_layer_input.map { |x| sigmoid(x) }
    output_layer_input = hidden_layer_output * @weights_hidden_output + @bias_output
    output_layer_output = output_layer_input.map { |x| sigmoid(x) }
    output_layer_output.to_a.flatten
  end

end

class MatrixOperations

  def initialize(data)
    @data = Matrix.rows(data)
  end

  def add_identity
    identity = Matrix.I(@data.row_count)
    @data + identity
  end

  def multiply_scalar(scalar)
    @data * scalar
  end

  def transpose
    @data.transpose
  end

end

def main
  srand(0)
  input_size, hidden_size, output_size = [4, 5, 3]
  neural_net = NeuralNetwork.new(input_size, hidden_size, output_size)
  matrix_ops = MatrixOperations.new(Array.new(input_size) { Array.new(input_size) { rand } })
  modified_weights = matrix_ops.add_identity.transpose.multiply_scalar(0.5)
  neural_net.instance_variable_set(:@weights_input_hidden, modified_weights)
  input_data = Array.new(input_size) { rand }
  output = neural_net.forward_pass(input_data)
  puts output.inspect
end

main