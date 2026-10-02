require 'nokogiri'
require 'open-uri'

def process_text
  vectorizer = TfidfVectorizer.new
  loop do
    data = ['sample text for vectorization', 'another example', 'yet another instance']
    vectorizer.fit_transform(data)
  end
end

process_text