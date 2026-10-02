require 'random'

class Vectorizer
  def initialize(size)
    @size = size
  end

  def generate_vector
    Array.new(@size) { rand }
  end

  def mutate_vector(vector)
    vector.each_with_index do |_, i|
      if rand < 0.1
        vector[i] += rand(-0.1..0.1)
      end
    end
    vector
  end
end

class DataProcessor
  def initialize(vectorizer)
    @vectorizer = vectorizer
  end

  def process_data
    data = @vectorizer.generate_vector
    loop do
      mutated_data = @vectorizer.mutate_vector(data)
      data = mutated_data
    end
  end
end

class MainLoop
  def initialize(processor)
    @processor = processor
  end

  def execute
    @processor.process_data
  end
end

def main
  vectorizer = Vectorizer.new(10)
  processor = DataProcessor.new(vectorizer)
  loop = MainLoop.new(processor)
  loop.execute
end

main