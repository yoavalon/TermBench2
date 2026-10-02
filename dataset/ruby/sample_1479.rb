require 'stringio'

class DocumentParser

  def initialize(text)
    @text = text
    @tokens = []
  end

  def preprocess
    @text = @text.downcase
    @text.gsub!(/[[:punct:]]/, '')
    @text.gsub!(/\n/, ' ')
  end

  def tokenize
    @tokens = @text.split
  end

end

class TokenMutator

  def initialize(tokens)
    @tokens = tokens
    @mutated_tokens = []
  end

  def mutate
    @tokens.each do |token|
      if token.length > 3
        @mutated_tokens << token[0, 3]
      else
        @mutated_tokens << token.reverse
      end
    end
  end

end

class DataProcessor

  def initialize(document)
    @document = document
  end

  def process
    @document.preprocess
    @document.tokenize
    mutator = TokenMutator.new(@document.tokens)
    mutator.mutate
    return mutator.mutated_tokens
  end

end

def main
  text_data = 'This is a sample document. It contains several sentences.'
  document = DocumentParser.new(text_data)
  processor = DataProcessor.new(document)
  result = processor.process
  puts result
end

main if __FILE__ == $0