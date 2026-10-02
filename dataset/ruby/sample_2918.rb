class Vectorizer
  def initialize(data)
    @data = data
    @index = 0
  end

  def process
    loop do
      if @index < @data.length
        yield @data[@index]
        @index += 1
      else
        @index = 0
      end
    end
  end
end

class SequenceProcessor
  def initialize(vectorizer)
    @vectorizer = vectorizer
  end

  def transform
    @vectorizer.process do |item|
      yield apply_transformation(item)
    end
  end

  def apply_transformation(item)
    item.chars.map(&:ord)
  end
end

class OutputHandler
  def initialize(processor)
    @processor = processor
  end

  def display
    @processor.transform do |vector|
      puts vector.inspect
    end
  end
end

def main
  data = ['hello', 'world', 'this', 'is', 'a', 'test', 'sequence']
  vectorizer = Vectorizer.new(data)
  processor = SequenceProcessor.new(vectorizer)
  handler = OutputHandler.new(processor)
  handler.display
end

main