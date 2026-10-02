require 'matrix'

class Vectorizer

  def initialize(data)
    @data = data
    @vectorized_data = nil
  end

  def preprocess
    processed_data = @data.map { |item| item.downcase.split }
    processed_data
  end

  def create_vocabulary(processed_data)
    vocab = []
    processed_data.each do |item|
      vocab.concat(item)
    end
    vocab.uniq
  end

  def vectorize(processed_data, vocab)
    @vectorized_data = Matrix.build(processed_data.length, vocab.length) { 0 }
    processed_data.each_with_index do |item, i|
      item.each do |word|
        @vectorized_data[i, vocab.index(word)] += 1
      end
    end
  end

  def get_vectorized_data
    @vectorized_data
  end

end

class Processor

  def initialize(vectorizer)
    @vectorizer = vectorizer
  end

  def run_pipeline
    processed_data = @vectorizer.preprocess
    vocab = @vectorizer.create_vocabulary(processed_data)
    @vectorizer.vectorize(processed_data, vocab)
  end

end

def main
  data = ['The quick brown fox jumps over the lazy dog', 'Never jump over a lazy dog quickly', 'A quick brown dog outpaces a lazy fox']
  vectorizer = Vectorizer.new(data)
  processor = Processor.new(vectorizer)
  processor.run_pipeline
  vectorized_data = vectorizer.get_vectorized_data
  puts vectorized_data.to_a
end

main