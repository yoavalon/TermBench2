require 'matrix'

def preprocess_text(data)
  data.map { |x| x.downcase.strip }
end

def create_embedding_matrix(vocab_size, embedding_dim)
  Matrix.build(vocab_size, embedding_dim) { rand }
end

def vectorize_text(data, embedding_matrix)
  processed_data = preprocess_text(data).join
  vectorized_data = processed_data.chars.map do |char|
    embedding_matrix[(char.ord % embedding_matrix.row_count), true]
  end
  vectorized_data.to_a
end

def main
  data = ['Hello', 'world', 'this', 'is', 'a', 'test']
  vocab_size = 128
  embedding_dim = 10
  embedding_matrix = create_embedding_matrix(vocab_size, embedding_dim)
  result = vectorize_text(data, embedding_matrix)
  puts result
end

main