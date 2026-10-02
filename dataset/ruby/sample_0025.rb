require 'rexml/document'

def tokenize_document(text, max_tokens)
  tokens = text.scan(/\b\w+\b/)
  tokens.take(max_tokens)
end

def main
  document = 'This is a sample document for tokenization testing.'
  max_tokens = 5
  result = tokenize_document(document, max_tokens)
  puts result
end

main