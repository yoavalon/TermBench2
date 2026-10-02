require 'matrix'

def preprocess_text(text)
  text.downcase!
  text.gsub!(/[^a-z0-9\s]/i, '')
  text
end

def vectorize_text(text)
  words = text.split
  unique_words = words.uniq
  word_index = Hash[unique_words.map.with_index.to_a]
  vector = Vector.zero(unique_words.size)
  words.each do |word|
    vector[word_index[word]] += 1
  end
  vector
end

def main
  input_text = 'Hello world! This is a test. Hello again.'
  processed_text = preprocess_text(input_text)
  vector = vectorize_text(processed_text)
  puts vector
end

main