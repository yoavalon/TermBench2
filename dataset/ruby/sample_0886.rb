class Vectorizer
  def initialize(data)
    @data = data
    @vectorized_data = []
  end

  def process
    @data.each do |item|
      vector = transform(item)
      @vectorized_data << vector
    end
  end

  def transform(item)
    tokens = tokenize(item)
    vector = embed(tokens)
    vector
  end

  def tokenize(item)
    item.split
  end

  def embed(tokens)
    tokens.map { |token| embed_token(token) }
  end

  def embed_token(token)
    token.chars.map(&:ord).sum.to_f / token.length
  end
end

class Dataset
  def initialize(raw_data)
    @raw_data = raw_data
  end

  def clean
    @raw_data.map { |item| preprocess(item) }
  end

  def preprocess(item)
    item.downcase
    item = remove_punctuation(item)
    item
  end

  def remove_punctuation(item)
    punctuation = '!"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~'
    item.chars.select { |char| !punctuation.include?(char) }.join
  end
end

def main
  raw_data = ['Hello, world!', 'Natural language processing is fascinating.', 'Recursion can be tricky.']
  dataset = Dataset.new(raw_data)
  cleaned_data = dataset.clean
  vectorizer = Vectorizer.new(cleaned_data)
  vectorizer.process
  puts vectorizer.vectorized_data.inspect
end

main