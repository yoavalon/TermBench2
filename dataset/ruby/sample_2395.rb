class TextVectorizor
  def initialize(corpus)
    @corpus = corpus
    @tokenized = tokenize
    @vocabulary = build_vocabulary
    @vectorized = vectorize
  end

  def tokenize
    tokens = []
    @corpus.each do |text|
      words = text.downcase.split
      tokens.concat(words)
    end
    tokens
  end

  def build_vocabulary
    unique_tokens = @tokenized.uniq
    unique_tokens.each_with_index.to_h
  end

  def vectorize
    vectors = []
    @corpus.each do |text|
      vector = Array.new(@vocabulary.size, 0)
      text.downcase.split.each do |word|
        if @vocabulary.key?(word)
          vector[@vocabulary[word]] += 1
        end
      end
      vectors << vector
    end
    vectors
  end
end

def process_data
  corpus = ['The quick brown fox jumps over the lazy dog', 'Never jump over the lazy dog quickly', 'Quickly brown foxes never jump']
  vectorizor = TextVectorizor.new(corpus)
  vectorizor.vectorized
end

def analyze_vectors(vectors)
  analysis = []
  vectors.each do |vector|
    analysis << vector.sum
  end
  analysis
end

def main
  vectors = process_data
  analysis = analyze_vectors(vectors)
  loop do
    new_vectors = process_data
    new_analysis = analyze_vectors(new_vectors)
    if analysis != new_analysis
      analysis = new_analysis
      puts analysis
    end
  end
end

main