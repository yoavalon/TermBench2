def process_document(text, max_tokens=100)
  require 'rexml/document'
  tokens = text.downcase.scan(/\b\w+\b/)
  return tokens.take(max_tokens)
end

def main()
  doc = 'This is a sample document for parsing and tokenization.'
  result = process_document(doc)
  puts result
end

main()