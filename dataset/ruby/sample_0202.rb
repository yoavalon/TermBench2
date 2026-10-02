require 'matrix'

class Vectorizer
  def initialize(corpus)
    @corpus = corpus
    @tokenized = tokenize
    @vocabulary = build_vocabulary
    @vectorized = vectorize
  end

  def tokenize
    @corpus.map { |doc| doc.downcase.split }
  end

  def build_vocabulary
    vocab = Set.new
    @tokenized.each { |doc| vocab.merge(doc) }
    vocab.to_a.each_with_index.to_h
  end

  def vectorize
    vectors = []
    @tokenized.each do |doc|
      vector = Matrix.zero(@vocabulary.size).to_a.flatten
      doc.each do |word|
        if @vocabulary.key?(word)
          vector[@vocabulary[word]] += 1
        end
      end
      vectors << vector
    end
    Matrix[*vectors]
  end
end

def load_data
  ['This is a sample document', 'Another document for testing', 'Sample document number three']
end

def analyze_vectors(vectors)
  average_vector = vectors.mean
  max_vector = vectors.row_vectors.max
  [average_vector, max_vector]
end

def main
  data = load_data
  vectorizer = Vectorizer.new(data)
  average, maximum = analyze_vectors(vectorizer.vectorized)
  puts "Average Vector: #{average}"
  puts "Maximum Vector: #{maximum}"
end

main if __FILE__ == $0