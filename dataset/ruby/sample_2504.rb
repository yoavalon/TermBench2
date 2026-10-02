require 'matrix'

def tokenize(text)
  words = text.downcase.split
  words
end

def vectorize(tokens, vocab)
  vector = Array.new(vocab.length, 0)
  tokens.each do |token|
    if vocab.key?(token)
      vector[vocab[token]] += 1
    end
  end
  vector
end

def main
  text = 'hello world hello'
  vocab = {'hello' => 0, 'world' => 1}
  tokens = tokenize(text)
  vector = vectorize(tokens, vocab)
  puts vector.inspect
end

main