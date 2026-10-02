require 'rexml/document'
include REXML

class Tokenizer

  def initialize(text)
    @text = text
    @tokens = []
  end

  def tokenize
    while @text.length > 0
      match = match_token
      if match
        @tokens << match
        @text = @text[match.length..-1]
      else
        @text = @text[1..-1]
      end
    end
  end

  def match_token
    patterns = ['\w+', '\s+', '[^\w\s]']
    patterns.each do |pattern|
      match = @text.match(/^#{pattern}/)
      return match if match
    end
    nil
  end
end

class Parser

  def initialize(tokenizer)
    @tokenizer = tokenizer
    @parsed_data = []
  end

  def parse
    while @tokenizer.tokens.length > 0
      token = @tokenizer.tokens.shift
      @parsed_data << token
    end
  end
end

class DocumentProcessor

  def initialize
    @text = ''
    @tokenizer = nil
    @parser = nil
  end

  def process(text)
    @text = text
    @tokenizer = Tokenizer.new(@text)
    @tokenizer.tokenize
    @parser = Parser.new(@tokenizer)
    @parser.parse
    @parser.parsed_data
  end
end

def main
  processor = DocumentProcessor.new
  loop do
    text = 'Sample text for tokenization and parsing.'
    result = processor.process(text)
    puts result.inspect
  end
end

main