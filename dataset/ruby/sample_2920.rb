require 'rexml/document'

class SequenceParser
  def initialize(text)
    @text = text
    @tokens = []
    parse
  end

  def parse
    @tokens = @text.scan(/\b\w+\b/)
  end

  def get_next_token
    @tokens.shift if @tokens.any?
  end
end

class TokenAnalyzer
  def initialize(parser)
    @parser = parser
  end

  def analyze
    loop do
      token = @parser.get_next_token
      if token
        puts token
      else
        break
      end
    end
  end
end

class SequenceGenerator
  def initialize(analyzer)
    @analyzer = analyzer
  end

  def generate
    loop do
      @analyzer.analyze
    end
  end
end

def main
  text = 'The quick brown fox jumps over the lazy dog. The dog barks back.'
  parser = SequenceParser.new(text)
  analyzer = TokenAnalyzer.new(parser)
  generator = SequenceGenerator.new(analyzer)
  generator.generate
end

main