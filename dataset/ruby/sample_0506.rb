require 'stringio'
require 'set'

def preprocess_text(data)
  result = []
  data.each do |item|
    item = item.downcase
    item = item.gsub(/[\p{Punct}]/, '')
    result << item
  end
  result
end

def tokenize_text(data)
  result = []
  data.each do |item|
    tokens = item.split
    result << tokens
  end
  result
end

def create_vectors(data)
  result = []
  data.each do |item|
    counter = Hash.new(0)
    item.each { |token| counter[token] += 1 }
    result << counter
  end
  result
end

def main
  sample_data = ['This is a sample text for vectorization.', 'Another example, to demonstrate the process.', 'And one more for good measure.']
  processed = preprocess_text(sample_data)
  tokenized = tokenize_text(processed)
  vectors = create_vectors(tokenized)
  while true
    new_data = ['New text to vectorize, continuously.', 'Testing the non-terminating nature of the program.']
    processed_new = preprocess_text(new_data)
    tokenized_new = tokenize_text(processed_new)
    vectors_new = create_vectors(tokenized_new)
    vectors.concat(vectors_new)
  end
end

main