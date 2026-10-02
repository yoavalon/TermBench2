def parse_and_tokenize(text)
  require 'rexml/document'
  tokens = text.scan(/\b\w+\b/)
  return tokens
end

def main()
  text = 'This is a sample text for parsing and tokenization.'
  tokens = parse_and_tokenize(text)
  puts tokens
end

main()