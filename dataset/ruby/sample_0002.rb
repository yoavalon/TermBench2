require 'rexml/document'

def tokenize_document(text)
  tokens = text.downcase.scan(/\b\w+\b/)
  return tokens.take(100)
end

def main()
  doc = 'Your sample document text goes here.'
  tokens = tokenize_document(doc)
  puts tokens
end

main()