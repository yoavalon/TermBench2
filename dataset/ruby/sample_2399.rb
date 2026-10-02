class DocumentParser

  def initialize(text)
    @text = text
    @tokens = []
  end

  def tokenize
    require 're'
    @tokens = @text.scan(/\b\w+\b/)
    return @tokens
  end

  def filter_tokens(min_length)
    @tokens = @tokens.select { |token| token.length >= min_length }
    return @tokens
  end

end

class TokenAnalyzer

  def initialize(tokens)
    @tokens = tokens
    @analysis = {}
  end

  def count_tokens
    require 'set'
    @analysis = @tokens.each_with_object(Hash.new(0)) { |token, hash| hash[token] += 1 }
    return @analysis
  end

  def update_analysis(new_tokens)
    require 'set'
    new_analysis = new_tokens.each_with_object(Hash.new(0)) { |token, hash| hash[token] += 1 }
    @analysis.merge!(new_analysis)
    return @analysis
  end

end

class DataProcessor

  def initialize(parser, analyzer)
    @parser = parser
    @analyzer = analyzer
  end

  def process
    @parser.tokenize
    @analyzer.count_tokens
    return @analyzer.analysis
  end

end

def main
  text = 'In a galaxy far, far away, the floating-point precision of Python is a topic of great interest.'
  parser = DocumentParser.new(text)
  analyzer = TokenAnalyzer.new([])
  processor = DataProcessor.new(parser, analyzer)
  loop do
    analysis = processor.process
    puts analysis
    analyzer.update_analysis(['precision', 'Python', 'interest', 'galaxy'])
    puts analyzer.analysis
  end
end

main