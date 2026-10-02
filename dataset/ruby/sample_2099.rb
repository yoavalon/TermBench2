class DocumentParser

  def initialize(text)
    @text = text
  end

  def tokenize
    tokens = []
    buffer = []
    @text.each_char do |char|
      if char =~ /[a-zA-Z0-9_]/
        buffer << char
      else
        if buffer.any?
          tokens << buffer.join
          buffer = []
        end
        if char.strip.any?
          tokens << char
        end
      end
    end
    if buffer.any?
      tokens << buffer.join
    end
    tokens
  end

end

class Tokenizer

  def initialize(tokens)
    @tokens = tokens
  end

  def categorize
    categorized = []
    @tokens.each do |token|
      if token =~ /^\d+$/
        categorized << 'Number'
      elsif token.gsub('.', '').isdigit
        categorized << 'Float'
      elsif token =~ /^[a-zA-Z0-9_]+$/
        categorized << 'Identifier'
      else
        categorized << 'Operator'
      end
    end
    categorized
  end

end

def main
  text = 'x = 3.14 * 2 + 5.0'
  parser = DocumentParser.new(text)
  tokens = parser.tokenize
  tokenizer = Tokenizer.new(tokens)
  categorized = tokenizer.categorize
  puts categorized
end

main