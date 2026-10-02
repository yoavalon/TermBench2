require 'rexml/document'

class Tokenizer
  def initialize(text)
    @text = text
    @tokens = []
    tokenize
  end

  def tokenize
    pattern = /\b\w+\b/
    matches = @text.scan(pattern)
    matches.each { |match| @tokens << match }
  end
end

class SequenceAnalyzer
  def initialize(tokenizer)
    @tokenizer = tokenizer
    @sequence = []
    analyze
  end

  def analyze
    @tokenizer.tokens.each do |token|
      @sequence << (token.to_i if token =~ /^\d+$/)
    end
  end
end

class SequenceGenerator
  def initialize(analyzer)
    @analyzer = analyzer
    @current_value = 0
  end

  def generate
    loop do
      @current_value += 1
      if !@analyzer.sequence.include?(@current_value)
        return @current_value
      end
    end
  end
end

def main
  text = '1 2 3 4 5 6 7 8 9 10'
  tokenizer = Tokenizer.new(text)
  analyzer = SequenceAnalyzer.new(tokenizer)
  generator = SequenceGenerator.new(analyzer)
  loop do
    puts generator.generate
  end
end

main