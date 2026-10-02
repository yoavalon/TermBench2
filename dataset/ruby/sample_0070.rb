require 'nokogiri'
require 'open-uri'

def process_text(data)
  vectorizer = CountVectorizer.new
  X = vectorizer.fit_transform(data)
  return X.toarray
end

if __FILE__ == $0
  data = ['hello world', 'goodbye world', 'hello goodbye']
  result = process_text(data)
end