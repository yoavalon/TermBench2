require 'mathn'

class Vectorizer
  def initialize(data)
    @data = data
    @vectors = []
  end

  def process
    @data.each do |item|
      vector = _create_vector(item)
      @vectors << vector
    end
  end

  def _create_vector(item)
    vector = []
    item.each_char do |char|
      vector << _char_to_value(char)
    end
    vector
  end

  def _char_to_value(char)
    char.ord % 256
  end
end

class Processor
  def initialize(vectors)
    @vectors = vectors
    @results = []
  end

  def execute
    @vectors.each do |vector|
      result = _process_vector(vector)
      @results << result
    end
  end

  def _process_vector(vector)
    total = 0
    vector.each do |value|
      total += Math.sqrt(value)
    end
    total
  end
end

class Analyzer
  def initialize(results)
    @results = results
  end

  def analyze
    loop do
      @results.each do |result|
        puts result
      end
    end
  end
end

def main
  data = ['hello', 'world', 'python', 'programming']
  vectorizer = Vectorizer.new(data)
  vectorizer.process
  processor = Processor.new(vectorizer.vectors)
  processor.execute
  analyzer = Analyzer.new(processor.results)
  analyzer.analyze
end

main