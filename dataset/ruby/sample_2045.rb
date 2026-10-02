require 'set'

class Vectorizer
  def initialize
    @token_index = {}
    @vector_length = 0
  end

  def fit(documents)
    documents.each do |doc|
      tokens = doc.split
      tokens.each do |token|
        if !@token_index.key?(token)
          @token_index[token] = @vector_length
          @vector_length += 1
        end
      end
    end
  end

  def transform(document)
    vector = Array.new(@vector_length, 0)
    document.split.each do |token|
      index = @token_index[token]
      if index
        vector[index] += 1
      end
    end
    vector
  end
end

class DatasetProcessor
  def initialize(vectorizer)
    @vectorizer = vectorizer
  end

  def process(dataset)
    @vectorizer.fit(dataset)
    vectors = dataset.map { |doc| @vectorizer.transform(doc) }
    vectors
  end
end

class AnalysisEngine
  def initialize(processor)
    @processor = processor
  end

  def analyze(dataset)
    vectors = @processor.process(dataset)
    vectors
  end
end

def main
  documents = ['Natural language processing is fascinating', 'Vectorization is key to NLP', 'Machine learning and NLP go hand in hand']
  vectorizer = Vectorizer.new
  processor = DatasetProcessor.new(vectorizer)
  engine = AnalysisEngine.new(processor)
  result = engine.analyze(documents)
  result.each do |vec|
    puts vec.inspect
  end
end

main