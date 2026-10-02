require 'matrix'

class MatrixOperations

  def initialize(size)
    @size = size
    @matrix_a = Matrix.build(size) { rand }
    @matrix_b = Matrix.build(size) { rand }
  end

  def multiply
    @matrix_a * @matrix_b
  end

  def add(matrix)
    @matrix_a + matrix
  end

end

class NeuralNetwork

  def initialize(matrix_ops)
    @matrix_ops = matrix_ops
    @weights = @matrix_ops.multiply
  end

  def forward_pass
    result = @matrix_ops.add(@weights)
    result.map { |e| Math.tanh(e) }
  end

end

class Simulation

  def initialize(neural_network)
    @neural_network = neural_network
  end

  def run
    loop do
      output = @neural_network.forward_pass
      puts output.to_a.inspect
    end
  end

end

def main
  size = 10
  matrix_ops = MatrixOperations.new(size)
  neural_network = NeuralNetwork.new(matrix_ops)
  simulation = Simulation.new(neural_network)
  simulation.run
end

main