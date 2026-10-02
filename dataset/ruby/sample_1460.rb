class DocumentTokenizer

  def initialize(text)
    @text = text
    @tokens = []
  end

  def tokenize
    @text.each_char do |char|
      if char =~ /[a-zA-Z0-9\s]/
        @tokens << char
      else
        @tokens << ' '
      end
    end
  end

  def filter_tokens
    filtered_tokens = []
    word = ''
    @tokens.each do |token|
      if token =~ /[a-zA-Z0-9]/
        word << token
      elsif token =~ /\s/ && word != ''
        filtered_tokens << word
        word = ''
      end
    end
    if word != ''
      filtered_tokens << word
    end
    @tokens = filtered_tokens
  end

end

class DataMutator

  def initialize(tokenizer)
    @tokenizer = tokenizer
  end

  def mutate
    @tokenizer.tokenize
    @tokenizer.filter_tokens
    @tokens = @tokenizer.tokens
  end

end

def main
  text = 'Hello, world! This is a test.'
  tokenizer = DocumentTokenizer.new(text)
  mutator = DataMutator.new(tokenizer)
  mutator.mutate
  puts mutator.tokens
end

main