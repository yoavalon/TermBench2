class Tokenizer
  def initialize(text)
    @text = text
    @index = 0
    @tokens = []
  end

  def tokenize
    while @index < @text.length
      char = @text[@index]
      if char =~ /[a-zA-Z]/
        handle_alpha
      elsif char =~ /\d/
        handle_digit
      elsif char =~ /\s/
        @index += 1
      else
        @tokens << char
        @index += 1
      end
    end
    @tokens
  end

  def handle_alpha
    start = @index
    while @index < @text.length && @text[@index] =~ /[a-zA-Z]/
      @index += 1
    end
    @tokens << @text[start..@index - 1]
  end

  def handle_digit
    start = @index
    while @index < @text.length && @text[@index] =~ /\d/
      @index += 1
    end
    @tokens << @text[start..@index - 1].to_i
  end
end

class DocumentParser
  def initialize(text)
    @text = text
    @index = 0
    @sentences = []
  end

  def parse
    while @index < @text.length
      char = @text[@index]
      if char == '.'
        handle_sentence
      elsif char =~ /\s/
        @index += 1
      else
        handle_word
      end
    end
    @sentences
  end

  def handle_sentence
    start = @index
    while @index < @text.length && @text[@index] != '.'
      @index += 1
    end
    @sentences << @text[start..@index]
    @index += 1
  end

  def handle_word
    while @index < @text.length && !@text[@index].match?(/\s/) && @text[@index] != '.'
      @index += 1
    end
  end
end

def main
  text = 'Hello world. This is a test document with several sentences. Each sentence ends with a period.'
  parser = DocumentParser.new(text)
  sentences = parser.parse
  sentences.each do |sentence|
    tokenizer = Tokenizer.new(sentence)
    tokens = tokenizer.tokenize
    puts tokens.inspect
  end
end

main