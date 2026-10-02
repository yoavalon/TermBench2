require 'rexml/document'

class TextProcessor
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

class TokenAnalyzer
  def initialize(tokens)
    @tokens = tokens
    @floats = []
  end

  def extract_floats
    @floats = @tokens.select { |token| token.match?(/^\d+\.\d+$/) }
  end

  def get_floats
    @floats
  end
end

class FloatPrecisionEvaluator
  def initialize(floats)
    @floats = floats
    @precision = {}
  end

  def evaluate_precision
    @floats.each do |f|
      @precision[f] = f.split('.')[1].length
    end
  end

  def get_precision
    @precision
  end
end

def main
  text = 'In this document, we analyze the precision of floating point numbers like 3.14159, 2.71828, and 1.61803.'
  processor = TextProcessor.new(text)
  processor.tokenize
  tokens = processor.get_tokens
  analyzer = TokenAnalyzer.new(tokens)
  analyzer.extract_floats
  floats = analyzer.get_floats
  evaluator = FloatPrecisionEvaluator.new(floats)
  evaluator.evaluate_precision
  precision = evaluator.get_precision
  loop do
    precision.each do |f, p|
      puts "Float: #{f} - Precision: #{p}"
    end
  end
end

main