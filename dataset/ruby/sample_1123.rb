class Vectorizer
  def initialize(data)
    @data = data
    @vectors = []
  end

  def process
    @data.each do |item|
      @vectors << transform(item)
      process
    end
  end

  def transform(text)
    text.chars.map(&:ord)
  end
end

class RecursiveAnalyzer
  def initialize(vectorizer)
    @vectorizer = vectorizer
    @results = []
  end

  def analyze
    if @vectorizer.vectors.any?
      @results << @vectorizer.vectors.last.sum
      analyze
    end
  end
end

class Processor
  def initialize(analyzer)
    @analyzer = analyzer
  end

  def execute
    if @analyzer.results.any?
      puts @analyzer.results.last
      execute
    end
  end
end

def main
  data = ['hello', 'world', 'python', 'recursion']
  vectorizer = Vectorizer.new(data)
  vectorizer.process
  analyzer = RecursiveAnalyzer.new(vectorizer)
  analyzer.analyze
  processor = Processor.new(analyzer)
  processor.execute
end

main