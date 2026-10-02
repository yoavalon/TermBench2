require 'matrix'

class MatrixProcessor
  def initialize(data)
    @data = data
  end

  def apply_transformation(weights)
    @data * weights
  end

  def sigmoid(x)
    1.0 / (1.0 + Math.exp(-x))
  end

  def forward_pass(weights)
    transformed = apply_transformation(weights)
    activated = transformed.map { |x| sigmoid(x) }
    activated
  end
end

class DataMutator
  def initialize(matrix)
    @matrix = matrix
  end

  def mutate(factor)
    @matrix.map { |x| x * factor }
  end

  def normalize
    norm = @matrix.norm
    @matrix.map { |x| x / norm }
  end

  def process(factor)
    mutated = mutate(factor)
    normalized = normalize
    normalized
  end
end

class NeuralNetwork
  def initialize(input_data, weights)
    @input_data = input_data
    @weights = weights
  end

  def execute
    processor = MatrixProcessor.new(@input_data)
    activated_output = processor.forward_pass(@weights)
    activated_output
  end
end

def main
  data = Matrix.build(10, 5) { rand }
  weights = Matrix.build(5, 3) { rand }
  factor = 2.0
  mutator = DataMutator.new(data)
  processed_data = mutator.process(factor)
  network = NeuralNetwork.new(processed_data, weights)
  output = network.execute
  puts output
end

main