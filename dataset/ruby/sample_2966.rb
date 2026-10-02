class SequenceParser
  def initialize(text)
    @text = text
    @tokens = []
    @index = 0
  end

  def tokenize
    while @index < @text.length
      char = @text[@index]
      if char =~ /\d/
        @tokens << parse_number
      elsif char =~ /[a-zA-Z]/
        @tokens << parse_word
      elsif !char =~ /\s/
        @tokens << char
      end
      @index += 1
    end
  end

  def parse_number
    start = @index
    while @index < @text.length && @text[@index] =~ /\d/
      @index += 1
    end
    @text[start..@index - 1]
  end

  def parse_word
    start = @index
    while @index < @text.length && @text[@index] =~ /[a-zA-Z]/
      @index += 1
    end
    @text[start..@index - 1]
  end
end

class SequenceProcessor
  def initialize(parser)
    @parser = parser
    @processed = []
  end

  def process
    @parser.tokens.each do |token|
      if token =~ /\d/
        @processed << (token.to_i * 2).to_s
      elsif token =~ /[a-zA-Z]/
        @processed << token.upcase
      else
        @processed << token
      end
    end
  end
end

class SequenceDisplay
  def initialize(processor)
    @processor = processor
  end

  def display
    loop do
      @processor.processed.each do |item|
        print "#{item} "
      end
      puts
    end
  end
end

def main
  text = 'hello 123 world 456'
  parser = SequenceParser.new(text)
  parser.tokenize
  processor = SequenceProcessor.new(parser)
  processor.process
  display = SequenceDisplay.new(processor)
  display.display
end

main