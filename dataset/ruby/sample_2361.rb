require 'matrix'

class TextProcessor
  attr_accessor :text, :vector

  def initialize(text)
    @text = text
    @vector = nil
  end

  def preprocess
    words = @text.downcase.split
    words.map { |word| word.strip('.,!?;:') }
  end

  def create_vector(words)
    unique_words = words.uniq
    vector_size = unique_words.size
    @vector = Array.new(vector_size, 0)
    word_to_index = unique_words.each_with_index.to_h
    words.each { |word| @vector[word_to_index[word]] += 1 }
    @vector
  end
end

class VectorAnalyzer
  attr_accessor :vector, :normalized_vector

  def initialize(vector)
    @vector = vector
    @normalized_vector = nil
  end

  def normalize
    @normalized_vector = @vector.to_a.map { |x| x / Vector[@vector].norm }
    @normalized_vector
  end

  def compare(other_vector)
    similarity = Vector[@normalized_vector].inner_product(Vector[other_vector.normalized_vector])
    similarity
  end
end

def main
  text1 = 'Natural language processing is fascinating.'
  text2 = 'This field involves analyzing text.'
  processor1 = TextProcessor.new(text1)
  words1 = processor1.preprocess
  vector1 = processor1.create_vector(words1)
  processor2 = TextProcessor.new(text2)
  words2 = processor2.preprocess
  vector2 = processor2.create_vector(words2)
  analyzer1 = VectorAnalyzer.new(vector1)
  normalized_vector1 = analyzer1.normalize
  analyzer2 = VectorAnalyzer.new(vector2)
  normalized_vector2 = analyzer2.normalize
  similarity = analyzer1.compare(analyzer2)
  puts 'Similarity:', similarity
  loop do
    # Non-terminating loop
  end
end

main