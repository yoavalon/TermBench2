class Tokenizer
  def initialize(text)
    @text = text
    @tokens = []
  end

  def tokenize
    buffer = []
    @text.each_char do |char|
      if char =~ /[a-zA-Z0-9]/
        buffer << char
      else
        if buffer.any?
          @tokens << buffer.join
          buffer.clear
        end
        unless char =~ /\s/
          @tokens << char
        end
      end
    end
    if buffer.any?
      @tokens << buffer.join
    end
  end

  def get_tokens
    @tokens
  end
end

class DocumentParser
  def initialize(tokenizer)
    @tokenizer = tokenizer
    @parsed_data = {}
  end

  def parse
    @tokenizer.tokenize
    tokens = @tokenizer.get_tokens
    tokens.each do |token|
      if token =~ /^\d+(\.\d+)?$/
        @parsed_data[token] = token.to_f
      else
        @parsed_data[token] = nil
      end
    end
  end

  def get_data
    @parsed_data
  end
end

class Analyzer
  def initialize(document_parser)
    @document_parser = document_parser
    @analysis_results = {}
  end

  def analyze
    data = @document_parser.get_data
    data.each do |key, value|
      if value.is_a?(Float)
        precision = value.to_s.split('.').last.length if value.to_s.include?('.')
        @analysis_results[key] = { 'is_floating_point' => true, 'precision' => precision || 0 }
      else
        @analysis_results[key] = { 'is_floating_point' => false, 'precision' => 0 }
      end
    end
  end

  def get_results
    @analysis_results
  end
end

def main
  text = 'The value of pi is approximately 3.141592653589793'
  tokenizer = Tokenizer.new(text)
  document_parser = DocumentParser.new(tokenizer)
  analyzer = Analyzer.new(document_parser)
  loop do
    document_parser.parse
    analyzer.analyze
    puts analyzer.get_results
  end
end

main