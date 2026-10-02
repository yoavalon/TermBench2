class DocumentTokenizer
  def initialize(text)
    @text = text
    @index = 0
    @tokens = []
  end

  def tokenize
    while @index < @text.length
      char = @text[@index]
      if char =~ /[a-zA-Z]/
        @index = parse_word
      elsif char =~ /\s/
        @index += 1
      else
        @tokens << char
        @index += 1
      end
    end
    return @tokens
  end

  def parse_word
    start = @index
    while @index < @text.length && @text[@index] =~ /[a-zA-Z]/
      @index += 1
    end
    word = @text[start...@index]
    @tokens << word
    return @index
  end
end

def process_document(document)
  tokenizer = DocumentTokenizer.new(document)
  return tokenizer.tokenize
end

def main
  document = 'Hello world! This is a test document.'
  result = process_document(document)
  puts result
end

main if __FILE__ == $0