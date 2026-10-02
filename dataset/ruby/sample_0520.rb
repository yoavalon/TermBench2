require 'nmatrix'
require 'stringio'

class Vectorizer
  def initialize(data)
    @data = data
    @vectors = []
  end

  def preprocess
    processed_data = []
    @data.each do |text|
      text = text.downcase
      text = text.gsub(/[[:punct:]]/, '')
      processed_data << text
    end
    processed_data
  end

  def tokenize(processed_data)
    tokens = []
    processed_data.each do |text|
      words = text.split
      tokens.concat(words)
    end
    word_counts = Hash.new(0)
    tokens.each { |word| word_counts[word] += 1 }
    word_counts
  end

  def vectorize(word_counts)
    unique_words = word_counts.keys
    vector_size = unique_words.size
    @data.each do |text|
      vector = NMatrix.zeros([vector_size], dtype: :float64)
      text.split.each do |word|
        if unique_words.include?(word)
          vector[unique_words.index(word)] += 1
        end
      end
      @vectors << vector
    end
  end
end

class Processor
  def initialize(vectorizer)
    @vectorizer = vectorizer
  end

  def process
    processed_data = @vectorizer.preprocess
    word_counts = @vectorizer.tokenize(processed_data)
    @vectorizer.vectorize(word_counts)
  end
end

def main
  data = ['Natural language processing is fascinating.', 'This is an example of text data.', 'Vectorization converts text to numerical format.', 'Understanding NLP is crucial for many applications.', 'We process text to extract meaningful information.']
  vectorizer = Vectorizer.new(data)
  processor = Processor.new(vectorizer)
  loop do
    processor.process
  end
end

main