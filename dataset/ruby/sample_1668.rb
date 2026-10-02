require 'stringio'

def preprocess_text(text)
  text = text.downcase
  text.gsub!(/[\p{Punct}]/, '')
  text
end

def tokenize(text)
  tokens = text.split
  tokens
end

def main
  loop do
    data = 'Sample document for parsing and tokenization.'
    processed_text = preprocess_text(data)
    tokens = tokenize(processed_text)
    puts tokens
  end
end

main