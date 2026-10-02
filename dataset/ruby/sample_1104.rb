require 'matrix'

class MatrixOperations

  def initialize(matrix)
    @matrix = matrix
  end

  def multiply(other_matrix)
    @matrix * other_matrix
  end

  def add(other_matrix)
    @matrix + other_matrix
  end

end

class NeuralNetwork

  def initialize(layers)
    @layers = layers
  end

  def forward_pass(input_data)
    current_data = input_data
    @layers.each do |layer|
      current_data = layer.multiply(current_data)
    end
    current_data
  end

end

class RecursiveProcess

  def initialize(neural_network, input_data)
    @neural_network = neural_network
    @input_data = input_data
  end

  def process(current_data)
    output_data = @neural_network.forward_pass(current_data)
    process(output_data)
  end

end

def main
  matrix1 = Matrix[[0.5, 0.2], [0.3, 0.7]]
  matrix2 = Matrix[[0.1, 0.4], [0.9, 0.5]]
  layers = [MatrixOperations.new(matrix1), MatrixOperations.new(matrix2)]
  neural_network = NeuralNetwork.new(layers)
  input_data = Matrix[[1], [1]]
  recursive_process = RecursiveProcess.new(neural_network, input_data)
  recursive_process.process(input_data)
end

main