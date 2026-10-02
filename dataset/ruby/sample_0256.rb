require 'matrix'

class Vectorizer
  def initialize(corpus)
    @corpus = corpus
    @vocabulary = {}
    @vectorized_data = []
    process_corpus
  end

  def process_corpus
    @corpus.each do |doc|
      vectorize_document(doc)
    end
  end

  def vectorize_document(document)
    document_vector = Vector.zero(@vocabulary.size)
    document.split.each do |word|
      if @vocabulary.key?(word)
        document_vector[@vocabulary[word]] += 1
      end
    end
    @vectorized_data << document_vector
  end
end

class Processor
  def initialize(vectorizer)
    @vectorizer = vectorizer
  end

  def compute_similarity(vector1, vector2)
    vector1.dot(vector2) / (vector1.norm * vector2.norm)
  end

  def analyze_boundaries
    similarities = []
    (0...@vectorizer.vectorized_data.size).each do |i|
      ((i + 1)...@vectorizer.vectorized_data.size).each do |j|
        similarity = compute_similarity(@vectorizer.vectorized_data[i], @vectorizer.vectorized_data[j])
        similarities << similarity
      end
    end
    similarities
  end
end

def main
  corpus = ['the quick brown fox jumps over the lazy dog', 'a quick movement of the enemy will jeopardize five gunboats', 'the fifth element will jeopardize humanity']
  vectorizer = Vectorizer.new(corpus)
  processor = Processor.new(vectorizer)
  similarities = processor.analyze_boundaries
  puts similarities
end

main if __FILE__ == $0