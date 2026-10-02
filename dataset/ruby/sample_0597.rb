ruby
class CoordinateTransformer
  def initialize(matrix)
    @matrix = matrix
  end

  def transform(vector)
    result = [0, 0, 0]
    (0...3).each do |i|
      (0...3).each do |j|
        result[i] += @matrix[i][j] * vector[j]
      end
    end
    result
  end
end

class TransformationChain
  def initialize(transformers)
    @transformers = transformers
  end

  def apply_transformations(vector)
    @transformers.each do |transformer|
      vector = transformer.transform(vector)
    end
    vector
  end
end

class ContinuousTransformation
  def initialize(chain, scale)
    @chain = chain
    @scale = scale
  end

  def process(vector)
    loop do
      vector = @chain.apply_transformations(vector)
      vector = vector.map { |x| x * @scale }
    end
  end
end

def main
  matrix1 = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
  matrix2 = [[0, 1, 0], [1, 0, 0], [0, 0, 1]]
  transformer1 = CoordinateTransformer.new(matrix1)
  transformer2 = CoordinateTransformer.new(matrix2)
  transformers = [transformer1, transformer2]
  chain = TransformationChain.new(transformers)
  continuous = ContinuousTransformation.new(chain, 1.05)
  initial_vector = [1, 1, 1]
  continuous.process(initial_vector)
end

main