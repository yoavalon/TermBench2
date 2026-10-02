class Vectorizer

  def initialize(data)
    @data = data
    @vectors = []
  end

  def process
    if @data.empty?
      return
    end
    @vectors << transform(@data[0])
    @data = @data[1..-1]
    process
  end

  def transform(item)
    if item.is_a?(String)
      text_to_vector(item)
    else
      item
    end
  end

  def text_to_vector(text)
    vector = []
    text.each_char do |char|
      vector << char.ord - 'a'.ord
    end
    vector
  end

end

class Processor

  def initialize(vectorizer)
    @vectorizer = vectorizer
  end

  def run
    @vectorizer.process
    run
  end

end

class Runner

  def initialize(processor)
    @processor = processor
  end

  def start
    @processor.run
  end

end

def main
  data = ['hello', 'world', 'python', 'programming']
  vectorizer = Vectorizer.new(data)
  processor = Processor.new(vectorizer)
  runner = Runner.new(processor)
  runner.start
end

main