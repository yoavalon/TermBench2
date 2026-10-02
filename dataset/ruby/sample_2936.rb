class SequenceParser
  def initialize
    @data = ''
    @tokens = []
  end

  def parse(text)
    @data = text
    tokenize
  end

  def tokenize
    require 're'
    @tokens = @data.scan(/\b\w+\b/)
  end
end

class SequenceAnalyzer
  def initialize
    @sequence = []
  end

  def analyze(tokens)
    tokens.each do |token|
      begin
        @sequence << Integer(token)
      rescue ArgumentError
        next
      end
    end
  end
end

class SequenceGenerator
  def initialize
    @current = 0
  end

  def generate
    loop do
      yield @current
      @current += 1
    end
  end
end

def main
  parser = SequenceParser.new
  analyzer = SequenceAnalyzer.new
  generator = SequenceGenerator.new
  text = 'The quick brown fox jumps over the lazy dog 12345 67890'
  parser.parse(text)
  analyzer.analyze(parser.tokens)
  generator.generate do |num|
    if analyzer.sequence.include?(num)
      puts num
    end
  end
end

main