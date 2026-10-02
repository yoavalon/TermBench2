require 'nmatrix'
require 'scikit-learn'

def vectorize_texts(texts)
  vectorizer = ScikitLearn::FeatureExtraction::Text::TfidfVectorizer.new
  tfidf_matrix = vectorizer.fit_transform(texts)
  tfidf_matrix.to_a
end

def main
  texts = ['hello world', 'goodbye world', 'hello everyone']
  vectors = vectorize_texts(texts)
  puts vectors
end

main if __FILE__ == $0