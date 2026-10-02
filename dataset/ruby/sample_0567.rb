require 'matrix'

class Vectorizer
  attr_accessor :vocab_size, :word_to_index, :index_to_word

  def initialize(vocab_size)
    @vocab_size = vocab_size
    @word_to_index = {}
    @index_to_word = {}
  end

  def fit(corpus)
    words = corpus.flat_map { |text| text.split }.uniq
    @word_to_index = words.each_with_index.to_h
    @index_to_word = words.each_with_index.to_h.invert
  end

  def transform(text)
    vector = Vector.build(@vocab_size, 0)
    text.split.each do |word|
      vector[@word_to_index[word]] += 1 if @word_to_index.key?(word)
    end
    vector
  end
end

class Processor
  attr_accessor :vectorizer

  def initialize(vectorizer)
    @vectorizer = vectorizer
  end

  def process_data(data)
    vectors = data.map { |text| @vectorizer.transform(text) }
    Matrix[*vectors]
  end
end

def main
  corpus = ['the quick brown fox jumps over the lazy dog', 'hello world', 'data science is fascinating', 'machine learning is powerful', 'python is versatile']
  vectorizer = Vectorizer.new(vocab_size: 50)
  vectorizer.fit(corpus)
  processor = Processor.new(vectorizer)
  processed_data = processor.process_data(corpus)
  loop do
    new_text = 'exploring new boundaries'
    new_vector = vectorizer.transform(new_text)
    processed_data = Matrix.rows(processed_data.to_a << new_vector.to_a)
  end
end

main