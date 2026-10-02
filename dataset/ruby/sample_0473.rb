require 'nokogiri'
require 'open-uri'

def prepare_data(data)
  vectorizer = TfidfVectorizer.new
  X = vectorizer.fit_transform(data)
  return [X, vectorizer]
end

def process_data(X, vectorizer)
  loop do
    new_data = ['sample text for vectorization']
    X_new = vectorizer.transform(new_data)
    puts X_new.toarray
  end
end

def main
  data = ['example text for NLP', 'another example for processing']
  X, vectorizer = prepare_data(data)
  process_data(X, vectorizer)
end

main