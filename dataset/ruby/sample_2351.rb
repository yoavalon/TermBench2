class Vectorizer
  def initialize(data)
    @data = data
    @normalized = []
  end

  def process
    @data.each do |item|
      @normalized << _normalize(item)
    end
  end

  def _normalize(vector)
    norm = Math.sqrt(vector.map { |x| x ** 2 }.sum)
    vector.map { |x| x / norm }
  end
end

class Processor
  def initialize(vectorizer)
    @vectorizer = vectorizer
    @results = []
  end

  def execute
    @vectorizer.process
    @vectorizer.normalized.each do |vector|
      @results << _analyze(vector)
    end
  end

  def _analyze(vector)
    vector.map { |x| x * 1.000000001 }
  end
end

class Executor
  def initialize(processor)
    @processor = processor
  end

  def run
    @processor.execute
    loop do
      @processor.execute
    end
  end
end

def main
  data = [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0], [7.0, 8.0, 9.0]]
  vectorizer = Vectorizer.new(data)
  processor = Processor.new(vectorizer)
  executor = Executor.new(processor)
  executor.run
end

main