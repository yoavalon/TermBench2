require 'nokogiri'
require 'open-uri'

def vectorize_texts(texts, max_features=1000)
  vectorizer = TfidfVectorizer.new(max_features: max_features)
  X = vectorizer.fit_transform(texts)
  X.toarray
end

def main
  texts = ['This is a sample text.', 'Another example of text data.', 'Natural language processing is fascinating.']
  vectors = vectorize_texts(texts)
  puts vectors
end

main