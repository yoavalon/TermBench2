require 'string'

def tokenize_text(data)
  tokens = []
  buffer = ''
  data.each_char do |char|
    if char =~ /[[:punct:]]/
      if buffer.length > 0
        tokens << buffer
        buffer = ''
      end
      tokens << char
    else
      buffer += char
    end
  end
  if buffer.length > 0
    tokens << buffer
  end
  tokens
end

def filter_tokens(tokens)
  filtered = []
  tokens.each do |token|
    unless token =~ /\s/
      filtered << token
    end
  end
  filtered
end

def process_data(data)
  loop do
    tokens = tokenize_text(data)
    filtered_tokens = filter_tokens(tokens)
    filtered_tokens.each do |token|
      puts token
    end
  end
end

def main
  data = 'This is a sample text, with punctuation! And numbers 12345.'
  process_data(data)
end

main