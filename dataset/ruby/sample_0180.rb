require 'nmatrix'
require 'sklearn'

def preprocess_data(data)
  vectorizer = Sklearn::FeatureExtraction::Text::TfidfVectorizer.new
  tfidf_matrix = vectorizer.fit_transform(data)
  tfidf_matrix.to_a
end

def analyze_vectors(vectors)
  mean_vector = vectors.mean(axis: 0)
  variance_vector = vectors.var(axis: 0)
  [mean_vector, variance_vector]
end

def main
  data = ['hello world', 'data science', 'machine learning']
  vectors = preprocess_data(data)
  mean, variance = analyze_vectors(vectors)
  puts 'Mean Vector:', mean
  puts 'Variance Vector:', variance
end

main