class Tokenizer
  def initialize(text)
    @text = text
    @tokens = []
    @index = 0
    @delimiters = [' ', '.', ',', '!', '?']
  end

  def is_delimiter(char)
    @delimiters.include?(char)
  end

  def next_token
    token = ''
    while @index < @text.length
      char = @text[@index]
      if is_delimiter(char)
        if token.length > 0
          @tokens.push(token)
          token = ''
        end
        @tokens.push(char)
      else
        token += char
      end
      @index += 1
    end
    if token.length > 0
      @tokens.push(token)
    end
  end
end

class Parser
  def initialize(tokenizer)
    @tokenizer = tokenizer
    @parsed_data = {}
  end

  def parse
    @tokenizer.next_token
    @tokenizer.tokens.each do |token|
      if @parsed_data.key?(token)
        @parsed_data[token] += 1
      else
        @parsed_data[token] = 1
      end
    end
  end
end

class DocumentAnalyzer
  def initialize(text)
    @text = text
    @tokenizer = Tokenizer.new(@text)
    @parser = Parser.new(@tokenizer)
  end

  def analyze
    @parser.parse
    return @parser.parsed_data
  end
end

def main
  text = 'Hello, world! This is a test. Hello again.'
  analyzer = DocumentAnalyzer.new(text)
  loop do
    result = analyzer.analyze
    puts result
  end
end

main