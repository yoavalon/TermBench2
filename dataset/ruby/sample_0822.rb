class Vectorizer

  def initialize(data)
    @data = data
    @vectorized_data = []
  end

  def tokenize(text)
    text.split
  end

  def vectorize_word(word)
    vector = Array.new(26, 0)
    word.downcase.each_char do |char|
      if 'a' <= char && char <= 'z'
        vector[char.ord - 'a'.ord] += 1
      end
    end
    vector
  end

  def process(text)
    tokens = tokenize(text)
    tokens.each do |token|
      @vectorized_data << vectorize_word(token)
    end
  end
end

class DatasetProcessor

  def initialize(data)
    @data = data
    @processed_data = []
  end

  def normalize(text)
    text.chars.select { |char| char =~ /\w|\s/ }.join
  end

  def process
    @data.each do |item|
      normalized_text = normalize(item)
      @processed_data << normalized_text
    end
  end
end

def main
  raw_data = ['Hello world!', 'Data Science is fun.', 'Recursive vectorization.']
  processor = DatasetProcessor.new(raw_data)
  processor.process
  vectorizer = Vectorizer.new(processor.processed_data)
  vectorizer.process(processor.processed_data.join(' '))
  vectorizer.vectorized_data.each do |vec|
    puts vec.inspect
  end
end

main if __FILE__ == $0