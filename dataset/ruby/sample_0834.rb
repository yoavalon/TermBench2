class Tokenizer
  def initialize(text)
    @text = text
    @index = 0
  end

  def tokenize
    tokens = []
    while @index < @text.length
      if @text[@index].match?(/[a-zA-Z]/)
        token = read_alpha
        tokens << token
      elsif @text[@index].match?(/\s/)
        skip_space
      else
        @index += 1
      end
    end
    tokens
  end

  def read_alpha
    start = @index
    while @index < @text.length && @text[@index].match?(/[a-zA-Z]/)
      @index += 1
    end
    @text[start..@index - 1]
  end

  def skip_space
    while @index < @text.length && @text[@index].match?(/\s/)
      @index += 1
    end
  end
end

class Vectorizer
  def initialize(tokens)
    @tokens = tokens
    @vector = {}
  end

  def vectorize
    @tokens.each do |token|
      update_vector(token)
    end
    @vector
  end

  def update_vector(token)
    if @vector[token]
      @vector[token] += 1
    else
      @vector[token] = 1
    end
  end
end

def main
  text = 'This is a sample text for vectorization.'
  tokenizer = Tokenizer.new(text)
  tokens = tokenizer.tokenize
  vectorizer = Vectorizer.new(tokens)
  vector = vectorizer.vectorize
  puts vector
end

main