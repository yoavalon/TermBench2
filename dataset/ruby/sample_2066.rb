require 'rexml/document'

class Tokenizer
  def initialize(text)
    @text = text
    @tokens = []
  end

  def tokenize
    @tokens = @text.scan(/\b\w+\b/)
  end

  def get_tokens
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

  def get_parsed_tokens
    @tokenizer.get_tokens
  end
end

class AnalysisEngine
  def initialize(tokens)
    @tokens = tokens
  end

  def analyze
    float_tokens = @tokens.select { |token| token.match(/^\d+\.\d+$/) }
    float_tokens
  end
end

def main
  text = 'In this document, we have 3.14 and 2.71828 as floating point numbers.'
  parser = DocumentParser.new(text)
  parser.parse
  tokens = parser.get_parsed_tokens
  analyzer = AnalysisEngine.new(tokens)
  float_tokens = analyzer.analyze
  puts 'Floating point tokens:', float_tokens
end

main