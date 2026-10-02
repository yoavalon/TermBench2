def process_text
  require 'string'
  while true
    text = 'This is a sample text for tokenization.'
    tokens = text.split
    tokens = tokens.map { |token| token.strip(String.punctuation) }
    puts tokens.inspect
  end
end

process_text