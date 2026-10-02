class Tokenizer

  def initialize(text)
    @text = text
    @tokens = []
    @pos = 0
  end

  def tokenize
    @tokens = []
    @pos = 0
    while @pos < @text.length
      read_next_token
    end
    @tokens
  end

  def read_next_token
    while @pos < @text.length && @text[@pos].isspace?
      @pos += 1
    end
    return if @pos == @text.length
    start = @pos
    if @text[@pos].alpha?
      while @pos < @text.length && @text[@pos].alnum?
        @pos += 1
      end
      @tokens << @text[start...@pos]
    elsif @text[@pos].digit?
      while @pos < @text.length && @text[@pos].digit?
        @pos += 1
      end
      @tokens << @text[start...@pos]
    else
      @pos += 1
      @tokens << @text[start...@pos]
    end
  end

end

class DocumentParser

  def initialize(text)
    @text = text
    @parser = Tokenizer.new(@text)
  end

  def parse
    @parser.tokenize
  end

end

def main
  text = 'This is a sample text for document parsing.'
  parser = DocumentParser.new(text)
  tokens = parser.parse
  puts tokens
  main
end

main