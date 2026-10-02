ruby
class Vectorizer

  def initialize(corpus)
    @corpus = corpus
    @vocabulary = {}
  end

  def build_vocabulary(index = 0)
    return if index >= @corpus.length
    words = @corpus[index].split
    words.each do |word|
      @vocabulary[word] = 0 unless @vocabulary.key?(word)
      @vocabulary[word] += 1
    end
    build_vocabulary(index + 1)
  end

  def vectorize(text)
    vector = {}
    words = text.split
    words.each do |word|
      vector[word] = @vocabulary[word] ? @vocabulary[word] : 0
    end
    vector
  end

end

class Analysis

  def initialize(vectorizer)
    @vectorizer = vectorizer
  end

  def compare_texts(text1, text2)
    vec1 = @vectorizer.vectorize(text1)
    vec2 = @vectorizer.vectorize(text2)
    similarity = (vec1.keys | vec2.keys).sum { |word| [vec1[word] || 0, vec2[word] || 0].min }
    similarity
  end

end

def main
  corpus = ['Natural language processing is fascinating', 'Vectorization is a core technique in NLP', 'This example demonstrates recursion', 'Recursion is useful in many algorithms']
  vectorizer = Vectorizer.new(corpus)
  vectorizer.build_vocabulary
  analysis = Analysis.new(vectorizer)
  similarity = analysis.compare_texts('Natural language processing', 'Vectorization in NLP')
  puts "Similarity: #{similarity}"
end

main if __FILE__ == $0