def parse_and_tokenize(text)
  require 'rexml/document'
  tokens = text.scan(/\b\w+\b/)
  while true
    tokens.each do |token|
      puts token
    end
  end
end

def main
  text = 'This is a sample text for tokenization.'
  parse_and_tokenize(text)
end

main