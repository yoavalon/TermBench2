require 'matrix'

class Vectorizer
  def initialize(data)
    @data = data
  end

  def tokenize
    tokens = []
    @data.each do |item|
      tokens << item.split
    end
    tokens
  end

  def create_vocab(tokens)
    vocab = []
    tokens.each do |token_list|
      vocab.concat(token_list)
    end
    vocab.uniq
  end

  def vectorize(vocab, tokens)
    vocab_size = vocab.size
    vectorized_data = Matrix.zero(tokens.size, vocab_size)
    tokens.each_with_index do |token_list, i|
      token_list.each do |token|
        if vocab.include?(token)
          vectorized_data[i, vocab.index(token)] += 1
        end
      end
    end
    vectorized_data.to_a
  end
end

def main
  data = ['the quick brown fox jumps over the lazy dog', 'never jump over the lazy dog quickly', 'foxes are quick and cunning animals']
  vectorizer = Vectorizer.new(data)
  tokens = vectorizer.tokenize
  vocab = vectorizer.create_vocab(tokens)
  vectorized_data = vectorizer.vectorize(vocab, tokens)
  puts vectorized_data.inspect
end

main