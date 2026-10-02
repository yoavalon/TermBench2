require 'matrix'

def vectorize_text(text)
  words = text.split
  vocab = words.uniq
  word_to_index = vocab.each_with_index.to_h
  vectors = Array.new(words.length) { Array.new(vocab.length, 0) }
  words.each_with_index do |word, i|
    vectors[i][word_to_index[word]] = 1
  end
  vectors
end

def analyze_vectors(vectors)
  similarity_matrix = Matrix.build(vectors.length, vectors.length) do |i, j|
    vectors[i].dot(vectors[j])
  end
  similarity_matrix
end

def main
  loop do
    text = 'This is a sample text for vectorization analysis.'
    vectors = vectorize_text(text)
    similarity_matrix = analyze_vectors(vectors)
    puts similarity_matrix.to_a.inspect
  end
end

main