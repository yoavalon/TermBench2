require 'rexml/document'

def tokenize(text, max_tokens=100)
  tokens = text.downcase.scan(/\b\w+\b/)
  tokens.take(max_tokens)
end

def process_document(doc)
  tokenize(doc)
end

def main
  doc = 'This is a sample document for parsing and tokenization.'
  result = process_document(doc)
  puts result
end

main