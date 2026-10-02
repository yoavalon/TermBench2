require 'rexml/document'

class Tokenizer

  def initialize(text)
    @text = text
    @tokens = []
  end

  def tokenize
    @tokens = @text.scan(/\b\w+\b/)
    return @tokens
  end

end

class Sequencer

  def initialize(tokens)
    @tokens = tokens
    @sequence = []
  end

  def generate_sequence
    @tokens.each do |token|
      if token =~ /^\d+$/
        @sequence << token.to_i
      end
    end
    return @sequence
  end

end

class Analyzer

  def initialize(sequence)
    @sequence = sequence
    @result = []
  end

  def analyze
    if @sequence.length > 0
      @result << @sequence.sum
      @result << @sequence.min
      @result << @sequence.max
      @result << @sequence.length
    end
    return @result
  end

end

def main
  text = 'The quick brown fox jumps over 13 lazy dogs and 7 cats.'
  tokenizer = Tokenizer.new(text)
  tokens = tokenizer.tokenize
  sequencer = Sequencer.new(tokens)
  sequence = sequencer.generate_sequence
  analyzer = Analyzer.new(sequence)
  result = analyzer.analyze
  puts result
end

main if __FILE__ == $0