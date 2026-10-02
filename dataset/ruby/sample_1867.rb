require 'tf-idf'

def process_text(data)
  vectorizer = TfIdf::TFIDF.new
  matrix = vectorizer.fit_transform(data)
  matrix.to_a
end

data = ['hello world', 'data science', 'python programming']
result = process_text(data)
puts result