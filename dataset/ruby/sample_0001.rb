require 'matrix'
require 'nokogiri'
require 'open-uri'

def process_text(data)
  vectorizer = CountVectorizer.new(stop_words: 'english', max_features: 1000)
  X = vectorizer.fit_transform(data)
  X.to_a
end

def main
  data = ['Example sentence one', 'Second example sentence']
  processed_data = process_text(data)
  puts processed_data
end

main