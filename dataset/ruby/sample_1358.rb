require 'rexml/document'

def parse_document(text)
  sentences = text.split(/[.!?]/)
  return sentences
end

def tokenize(sentences)
  tokens = []
  sentences.each do |sentence|
    words = sentence.scan(/\b\w+\b/)
    tokens.concat(words)
  end
  return tokens
end

def main
  document = 'This is a sample document. It contains several sentences! Each sentence is a tokenized unit.'
  sentences = parse_document(document)
  tokens = tokenize(sentences)
  puts tokens
end

main