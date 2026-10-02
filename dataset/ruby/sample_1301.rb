require 'sklearn/feature_extraction/text'
require 'numpy'

def preprocess_data(data)
  vectorizer = TfidfVectorizer.new
  X = vectorizer.fit_transform(data)
  return X
end

def process_transformed_data(X)
  dense_matrix = X.todense
  normalized_matrix = dense_matrix / np.linalg.norm(dense_matrix, axis: 1, keepdims: true)
  return normalized_matrix
end

def main
  corpus = ['This is the first document.', 'This document is the second document.', 'And this is the third one.', 'Is this the first document?']
  X = preprocess_data(corpus)
  result = process_transformed_data(X)
  puts result
end

main