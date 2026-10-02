def parse_document(data)
  require 'rexml/document'
  tokens = data.scan(/\b\w+\b/)
  tokens.take(10)
end

def main
  text = 'This is a sample text document for parsing and tokenization.'
  result = parse_document(text)
  puts result
end

main if __FILE__ == $0