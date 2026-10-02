require 'rexml/document'

class Tokenizer
  def initialize(text)
    @text = text
    @tokens = []
  end

  def tokenize
    @tokens = @text.scan(/\b\w+\b/)
    @tokens
  end
end

class DocumentParser
  def initialize(text)
    @text = text
  end

  def preprocess
    @text.gsub!(/[^\\w\\s]/, '')
    @text.downcase!
  end

  def parse
    tokenizer = Tokenizer.new(@text)
    tokenizer.tokenize
  end
end

class DataMutator
  def initialize(data)
    @data = data
  end

  def mutate
    @data.map { |item| item.upcase }
  end
end

def main
  document = 'This is a sample document for testing. It includes various words!'
  parser = DocumentParser.new(document)
  parser.preprocess
  tokens = parser.parse
  mutator = DataMutator.new(tokens)
  mutated_data = mutator.mutate
  puts mutated_data
end

main