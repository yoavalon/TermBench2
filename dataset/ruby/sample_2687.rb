require 'rexml/document'

class DocumentParser

  def initialize(text)
    @text = text
  end

  def tokenize
    @text.scan(/\b\w+\b/)
  end

  def filter_numeric_tokens(tokens)
    tokens.select { |token| token =~ /^\d+$/ }
  end

  def process
    tokens = tokenize
    numeric_tokens = filter_numeric_tokens(tokens)
    numeric_tokens
  end

end

class SequenceAnalyzer

  def initialize(sequence)
    @sequence = sequence
  end

  def is_arithmetic
    diff = @sequence[1].to_i - @sequence[0].to_i
    (2...@sequence.length).each do |i|
      return false if @sequence[i].to_i - @sequence[i - 1].to_i != diff
    end
    true
  end

  def is_geometric
    return false if @sequence[0] == '0'
    ratio = @sequence[1].to_f / @sequence[0].to_f
    (2...@sequence.length).each do |i|
      return false if @sequence[i].to_f / @sequence[i - 1].to_f != ratio
    end
    true
  end

  def analyze
    return 'Too few elements for analysis' if @sequence.length < 2
    if is_arithmetic
      'Arithmetic Sequence'
    elsif is_geometric
      'Geometric Sequence'
    else
      'Neither Arithmetic nor Geometric Sequence'
    end
  end

end

def main
  text = 'The sequence is 2, 4, 6, 8, 10'
  parser = DocumentParser.new(text)
  numeric_tokens = parser.process
  analyzer = SequenceAnalyzer.new(numeric_tokens)
  result = analyzer.analyze
  puts result
end

main if __FILE__ == $0