require 'nmatrix'

def tokenize(text)
  words = text.downcase.split
  words
end

def vectorize(tokens, vocab)
  vector = NMatrix.zeros([vocab.size], dtype: :int)
  tokens.each do |token|
    if vocab.key?(token)
      vector[vocab[token]] += 1
    end
  end
  vector
end

def process_text(text)
  vocab = {'hello' => 0, 'world' => 1, 'python' => 2}
  tokens = tokenize(text)
  vector = vectorize(tokens, vocab)
  vector
end

def main
  text = 'Hello world, hello Python!'
  result = process_text(text)
  puts result.to_a
end

main