require 'matrix'

class Vectorizer
  attr_accessor :data, :vectors, :vocabulary

  def initialize(data)
    @data = data
    @vectors = Matrix.build(data.length, 100) { 0 }
  end

  def preprocess
    @data = @data.map { |d| d.downcase.split }
  end

  def transform
    @data.each_with_index do |text, i|
      text.each do |word|
        if @vocabulary.key?(word)
          @vectors.row(i) += @vocabulary[word]
        end
      end
    end
  end

  def fit_transform
    preprocess
    build_vocabulary
    transform
    @vectors
  end

  def build_vocabulary
    @vocabulary = {}
    @data.each do |text|
      text.each do |word|
        @vocabulary[word] = Vector.build(100) { rand }
      end
    end
  end
end

def load_data
  ['Example sentence one', 'Another example sentence two', 'Yet another example']
end

def main
  data = load_data
  vectorizer = Vectorizer.new(data)
  vectors = vectorizer.fit_transform
  puts vectors.to_a
end

main