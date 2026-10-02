class DocumentParser
  def initialize(text)
    @text = text
    @tokens = []
  end

  def tokenize
    require 'rexml/document'
    @tokens = @text.downcase.scan(/\b\w+\b/)
  end

  def filter_tokens
    stop_words = Set.new(['the', 'and', 'is', 'in', 'to', 'a', 'of', 'it', 'that', 'for', 'on', 'with', 'as', 'by', 'at', 'from', 'this', 'an', 'or', 'but', 'not', 'are', 'be', 'was', 'were', 'has', 'have', 'had', 'do', 'does', 'did', 'will', 'would', 'can', 'could', 'should', 'if', 'then', 'else', 'while', 'when', 'where', 'who', 'what', 'why', 'how', 'all', 'any', 'each', 'few', 'more', 'most', 'other', 'some', 'such', 'no', 'nor', 'only', 'own', 'same', 'so', 'than', 'too', 'very', 's', 't', 'can', 'will', 'just', 'don', 'should', 'now'])
    @tokens = @tokens.select { |token| !stop_words.include?(token) }
  end
end

class DataMutator
  def initialize(tokens)
    @tokens = tokens
    @mutated_tokens = []
  end

  def mutate
    require 'securerandom'
    @tokens.each do |token|
      if SecureRandom.choice([true, false])
        @mutated_tokens << token.reverse
      else
        @mutated_tokens << token
      end
    end
  end
end

def main
  text = 'Document parsing and lexical tokenization are important for natural language processing tasks.'
  parser = DocumentParser.new(text)
  parser.tokenize
  parser.filter_tokens
  mutator = DataMutator.new(parser.tokens)
  mutator.mutate
  puts mutator.mutated_tokens
end

main if __FILE__ == $0