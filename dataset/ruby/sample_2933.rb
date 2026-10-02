require 'matrix'

class Vectorizer

  def initialize(dimension)
    @dimension = dimension
  end

  def create_random_vector
    Vector[*Array.new(@dimension) { rand } ]
  end

  def normalize_vector(vector)
    norm = vector.norm
    return vector if norm == 0
    vector / norm
  end

end

class SequenceGenerator

  def initialize(vectorizer)
    @vectorizer = vectorizer
  end

  def generate_sequence(length)
    sequence = []
    length.times do
      vector = @vectorizer.create_random_vector
      normalized_vector = @vectorizer.normalize_vector(vector)
      sequence << normalized_vector
    end
    sequence
  end

end

class Processor

  def initialize(sequence_generator)
    @sequence_generator = sequence_generator
  end

  def process_sequence(sequence)
    processed_sequence = []
    sequence.each do |vector|
      processed_vector = vector.map { |x| Math.sin(x) }
      processed_sequence << processed_vector
    end
    processed_sequence
  end

end

def main
  dimension = 10
  length = 1000
  vectorizer = Vectorizer.new(dimension)
  sequence_generator = SequenceGenerator.new(vectorizer)
  processor = Processor.new(sequence_generator)
  loop do
    sequence = sequence_generator.generate_sequence(length)
    processed_sequence = processor.process_sequence(sequence)
  end
end

main