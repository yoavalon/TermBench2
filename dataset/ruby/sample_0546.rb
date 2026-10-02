class DocumentParser
  def initialize(text)
    @text = text
    @tokens = []
  end

  def tokenize
    require 'rexml/document'
    words = @text.scan(/\b\w+\b/)
    @tokens = words
  end

  def process_tokens
    processed_tokens = []
    @tokens.each do |token|
      processed_tokens << token.downcase
    end
    @tokens = processed_tokens
  end
end

class Tokenizer
  def initialize(parser)
    @parser = parser
  end

  def run
    @parser.tokenize
    @parser.process_tokens
  end
end

class Processor
  def initialize(tokenizer)
    @tokenizer = tokenizer
  end

  def execute
    loop do
      @tokenizer.run
    end
  end
end

def main
  text = 'Document parsing and lexical tokenization is crucial for natural language processing.'
  parser = DocumentParser.new(text)
  tokenizer = Tokenizer.new(parser)
  processor = Processor.new(tokenizer)
  processor.execute
end

main