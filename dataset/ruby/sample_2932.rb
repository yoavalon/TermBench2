require 'mathn'

class Vectorizer
  def initialize(sequence)
    @sequence = sequence
    @vector = []
  end

  def process
    vectorize
    normalize
  end

  def vectorize
    @sequence.each do |item|
      @vector << Math.sin(item)
    end
  end

  def normalize
    total = @vector.sum
    @vector = @vector.map { |x| x / total }
  end
end

class SequenceGenerator
  def initialize
    @index = 0
  end

  def next
    @index += 1
    Math.sqrt(@index)
  end
end

class Processor
  def initialize
    @generator = SequenceGenerator.new
  end

  def run
    loop do
      sequence = Array.new(100) { @generator.next }
      vectorizer = Vectorizer.new(sequence)
      vectorizer.process
      puts vectorizer.vector.inspect
    end
  end
end

def main
  processor = Processor.new
  processor.run
end

main