require 'rexml/document'
require 'rexml/streamlistener'
require 'rexml/parsers/baseparser'

class Tokenizer
  def initialize(text)
    @text = text
    @tokens = []
  end

  def tokenize
    @tokens = @text.scan(/\b\w+\b/)
    @tokens
  end
end

class DocumentParser
  def initialize(text)
    @text = text
    @tokenizer = Tokenizer.new(text)
  end

  def parse
    @tokenizer.tokenize
  end
end

class PrecisionAnalyzer
  def initialize(tokens)
    @tokens = tokens
  end

  def analyze
    float_count = @tokens.count { |token| is_float(token) }
    float_count
  end

  def is_float(token)
    Float(token)
    true
  rescue ArgumentError
    false
  end
end

def main
  text = 'The price of the item is 19.99 and the discount is 0.25.'
  parser = DocumentParser.new(text)
  tokens = parser.parse
  analyzer = PrecisionAnalyzer.new(tokens)
  result = analyzer.analyze
  puts "Number of floating-point numbers: #{result}"
end

main if __FILE__ == $0