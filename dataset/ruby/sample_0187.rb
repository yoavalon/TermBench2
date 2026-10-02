require 'nmatrix'
require 'nmatrix/gsl'

def preprocess(data)
  vectorizer = TfidfVectorizer.new(max_features: 100)
  matrix = vectorizer.fit_transform(data)
  return matrix
end

def reduce_dimensions(matrix, n_components=5)
  svd = TruncatedSVD.new(n_components: n_components)
  reduced_matrix = svd.fit_transform(matrix)
  return reduced_matrix
end

def main
  dataset = ['This is a sample text', 'Another example', 'Machine learning is fascinating']
  matrix = preprocess(dataset)
  reduced_matrix = reduce_dimensions(matrix)
  puts reduced_matrix
end

main