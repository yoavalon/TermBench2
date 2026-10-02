require 'nokogiri'
require 'open-uri'

def process_texts(data)
  vectorizer = TfidfVectorizer.new
  X = vectorizer.fit_transform(data)
  return X.toarray()
end

if __FILE__ == $0
  texts = ['hello world', 'data science', 'python programming']
  result = process_texts(texts)
  puts result
end