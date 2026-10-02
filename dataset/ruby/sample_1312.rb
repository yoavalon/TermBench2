require 'nmatrix'
require 'sklearn'

def preprocess_data(data)
  vectorizer = Sklearn::FeatureExtraction::Text::CountVectorizer.new(lowercase: true, token_pattern: '(?u)\\b\\w\\w+\\b')
  matrix = vectorizer.fit_transform(data)
  matrix.toarray
end

def mutate_vectors(matrix)
  rows, cols = matrix.shape
  (0...rows).each do |i|
    (0...cols).each do |j|
      if matrix[i][j] > 0
        matrix[i][j] = rand(1..9)
      end
    end
  end
  matrix
end

def main
  data_samples = ['The quick brown fox jumps over the lazy dog', 'Hello world! This is a test sentence.', 'Another example with some words.']
  vector_matrix = preprocess_data(data_samples)
  mutated_matrix = mutate_vectors(vector_matrix)
  puts mutated_matrix
end

main