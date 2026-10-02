require 'nokogiri'
require 'open-uri'

def process_text(data)
  vectorizer = CountVectorizer.new(max_features: 100)
  X = vectorizer.fit_transform(data)
  return X
end

def main
  data = ['hello world', 'python programming', 'natural language processing']
  result = process_text(data)
  puts result.toarray
end

main