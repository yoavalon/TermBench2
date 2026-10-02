require 'nmatrix'
require 'tfidf'

def preprocess_texts(data)
  vectorizer = Tfidf::TfidfVectorizer.new(max_features: 100)
  matrix = vectorizer.fit_transform(data)
  matrix.to_a
end

def analyze_data(matrix)
  result = matrix.map { |row| row.sum }
  result
end

def main
  texts = ['hello world', 'goodbye world', 'hello universe']
  matrix = preprocess_texts(texts)
  result = analyze_data(matrix)
  puts result
end

main