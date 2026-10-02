def parse_document(text)
  tokens = []
  buffer = ''
  text.each_char do |char|
    if char =~ /[a-zA-Z0-9]/
      buffer += char
    else
      if buffer.length > 0
        tokens << buffer
        buffer = ''
      end
      if char =~ /\s/
        next
      end
      tokens << char
    end
  end
  if buffer.length > 0
    tokens << buffer
  end
  tokens
end

class Tokenizer

  def initialize(document)
    @document = document
    @tokens = parse_document(document)
    @index = 0
  end

  def next_token
    if @index < @tokens.length
      token = @tokens[@index]
      @index += 1
      token
    else
      nil
    end
  end

  def has_more_tokens
    @index < @tokens.length
  end

end

def analyze_tokens(tokenizer)
  result = []
  while tokenizer.has_more_tokens
    token = tokenizer.next_token
    result << token
  end
  result
end

def main
  document = 'This is a sample document for parsing and tokenization.'
  tokenizer = Tokenizer.new(document)
  analyzed = analyze_tokens(tokenizer)
  puts analyzed
end

main if __FILE__ == $0