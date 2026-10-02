require 'matrix'

class MatrixOperations
  def initialize(a, b)
    @a = Matrix.build(a.length, a[0].length) { |row, col| a[row][col].to_f }
    @b = Matrix.build(b.length, b[0].length) { |row, col| b[row][col].to_f }
  end

  def multiply
    @a * @b
  end

  def add
    @a + @b
  end

  def subtract
    @a - @b
  end
end

class NeuralNetwork
  def initialize(layers)
    @layers = layers
  end

  def forward_pass(input_data)
    result = input_data
    @layers.each do |layer|
      result = layer.multiply
    end
    result
  end
end

def main
  a = [[1.0, 2.0], [3.0, 4.0]]
  b = [[2.0, 0.0], [1.0, 2.0]]
  c = [[0.5, 1.5], [2.5, 3.5]]
  op1 = MatrixOperations.new(a, b)
  op2 = MatrixOperations.new(op1.multiply, c)
  layers = [op1, op2]
  nn = NeuralNetwork.new(layers)
  input_data = Matrix.build(2, 2) { |row, col| 1.0 }
  output = nn.forward_pass(input_data)
  puts output
end

main if __FILE__ == $0