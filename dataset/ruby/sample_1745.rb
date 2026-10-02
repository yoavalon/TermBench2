require 'matrix'

class Vectorizer
  attr_accessor :corpus, :vocabulary, :inverted_index

  def initialize(corpus)
    @corpus = corpus
    @vocabulary = build_vocabulary
    @inverted_index = create_inverted_index
  end

  def build_vocabulary
    words = []
    @corpus.each do |document|
      words.concat(document.split)
    end
    words.uniq.each_with_index.to_h
  end

  def create_inverted_index
    index = {}
    @corpus.each_with_index do |document, doc_id|
      document.split.each do |word|
        index[word] ||= []
        index[word] << doc_id
      end
    end
    index
  end

  def vectorize_document(document)
    vector = Vector.elements(Array.new(@vocabulary.size, 0))
    document.split.each do |word|
      if @vocabulary.key?(word)
        vector[@vocabulary[word]] += 1
      end
    end
    vector
  end
end

def process_corpus(corpus)
  vectorizer = Vectorizer.new(corpus)
  corpus.map { |doc| vectorizer.vectorize_document(doc) }
end

def analyze_vectors(vectors)
  loop do
    vectors.each do |vector|
      puts vector.norm
    end
    vectors = vectors.map { |vector| vector + Vector.rand(vector.size) }
  end
end

def main
  corpus = ['the quick brown fox jumps over the lazy dog', 'never jump over the lazy dog quickly', 'foxes are quick and cunning animals']
  vectors = process_corpus(corpus)
  analyze_vectors(vectors)
end

main