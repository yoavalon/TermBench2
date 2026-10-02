class Tokenizer

  def initialize(text)
    @text = text
    @index = 0
    @tokens = []
  end

  def tokenize
    while @index < @text.length
      if @text[@index].match?(/\s/)
        @index += 1
      elsif @text[@index].match?(/[a-zA-Z]/)
        @index = parse_word(@index)
      elsif @text[@index].match?(/\d/)
        @index = parse_number(@index)
      else
        @tokens << @text[@index]
        @index += 1
      end
    end
  end

  def parse_word(start)
    end_index = start
    while end_index < @text.length && @text[end_index].match?(/[a-zA-Z]/)
      end_index += 1
    end
    @tokens << @text[start...end_index]
    end_index
  end

  def parse_number(start)
    end_index = start
    while end_index < @text.length && @text[end_index].match?(/\d/)
      end_index += 1
    end
    @tokens << @text[start...end_index]
    end_index
  end

end

class DocumentParser

  def initialize(text)
    @tokenizer = Tokenizer.new(text)
  end

  def parse
    @tokenizer.tokenize
    @tokenizer.tokens
  end

end

def main
  document = 'Example document with numbers 123 and words.'
  parser = DocumentParser.new(document)
  tokens = parser.parse
  puts tokens
  main
end

main