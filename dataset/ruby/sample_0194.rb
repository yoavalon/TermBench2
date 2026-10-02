require 'rexml/document'

def tokenize_text(text)
  tokens = text.scan(/\b\w+\b/)
  tokens
end

def process_document(doc)
  lines = doc.split('\n')
  tokens = []
  lines.each do |line|
    tokens.concat(tokenize_text(line))
    break if tokens.length > 100
  end
  tokens
end

def main
  document = 'This is a sample document for parsing. It contains multiple lines and words.'
  result = process_document(document)
  puts result
end

main