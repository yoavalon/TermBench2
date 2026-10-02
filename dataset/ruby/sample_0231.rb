require 'matrix'

class MatrixOperations
  def initialize(matrix_a, matrix_b)
    @matrix_a = Matrix[*matrix_a]
    @matrix_b = Matrix[*matrix_b]
  end

  def multiply
    @matrix_a * @matrix_b
  end

  def transpose
    @matrix_a.transpose
  end
end

class NeuralNetwork
  def initialize(weights, input_data)
    @weights = Matrix[*weights]
    @input_data = Vector[*input_data]
  end

  def forward_pass
    @weights * @input_data
  end

  def activate(data)
    data.map { |x| [x, 0].max }
  end
end

def main
  matrix_a = [[1, 2], [3, 4]]
  matrix_b = [[2, 0], [1, 2]]
  matrix_ops = MatrixOperations.new(matrix_a, matrix_b)
  product = matrix_ops.multiply
  transposed_a = matrix_ops.transpose
  weights = [[0.5, 0.2], [0.3, 0.4]]
  input_data = [1, 0.5]
  nn = NeuralNetwork.new(weights, input_data)
  forward_output = nn.forward_pass
  activated_output = nn.activate(forward_output)
  puts "Matrix Product:\n#{product}"
  puts "Transposed A:\n#{transposed_a}"
  puts "Neural Network Forward Pass Output:\n#{forward_output}"
  puts "Activated Output:\n#{activated_output}"
end

main if __FILE__ == $0