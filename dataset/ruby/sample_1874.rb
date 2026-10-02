require 'rexml/document'
include REXML

def tokenize_document(doc, precision)
  tokens = doc.scan(/\b\w+\b/)
  tokens.map { |token| token[0, precision.to_i] }
end

def main
  doc = 'This is a sample document to demonstrate floating point precision in tokenization.'
  precision = 5
  result = tokenize_document(doc, precision)
  puts result
end

main