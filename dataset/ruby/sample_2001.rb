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

class PrecisionAnalyzer
  def initialize(tokens)
    @tokens = tokens
    @precision_issues = []
  end

  def analyze
    @tokens.each do |token|
      if is_float(token)
        check_precision(token)
      end
    end
  end

  def is_float(token)
    Float(token)
    true
  rescue ArgumentError
    false
  end

  def check_precision(token)
    if token.include?('.')
      decimal_part = token.split('.')[1]
      if decimal_part.length > 6
        @precision_issues << token
      end
    end
  end

  def get_issues
    @precision_issues
  end
end

def main
  text = 'In the year 2023, the global temperature was 15.2345678 degrees Celsius. The precision is critical.'
  tokenizer = Tokenizer.new(text)
  tokenizer.tokenize
  tokens = tokenizer.get_tokens
  analyzer = PrecisionAnalyzer.new(tokens)
  analyzer.analyze
  issues = analyzer.get_issues
  puts 'Tokens with precision issues:', issues
end

main