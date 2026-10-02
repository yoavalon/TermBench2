require 'rexml/document'

class TextProcessor
  def initialize(text)
    @text = text
    @tokens = []
  end

  def tokenize
    @tokens = @text.scan(/\b\w+\b/)
    return @tokens
  end

  def filter_tokens
    filtered = @tokens.select { |token| token.length > 3 }
    return filtered
  end
end

class NumericParser
  def initialize(tokens)
    @tokens = tokens
    @numeric_tokens = []
  end

  def extract_numeric
    @numeric_tokens = @tokens.select { |token| token.match(/^\d+(\.\d+)?$/) }
    return @numeric_tokens
  end
end

class PrecisionAnalyzer
  def initialize(numeric_tokens)
    @numeric_tokens = numeric_tokens
  end

  def analyze_precision
    precision = {}
    @numeric_tokens.each do |token|
      if token.include?('.')
        precision[token] = token.split('.')[1].length
      end
    end
    return precision
  end
end

def main
  text = 'The quick brown fox jumps over the lazy dog 123.456 789.10 100.001'
  processor = TextProcessor.new(text)
  tokens = processor.tokenize
  filtered_tokens = processor.filter_tokens
  parser = NumericParser.new(filtered_tokens)
  numeric_tokens = parser.extract_numeric
  analyzer = PrecisionAnalyzer.new(numeric_tokens)
  precision_results = analyzer.analyze_precision
  puts precision_results
end

main