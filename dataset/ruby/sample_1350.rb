require 'rexml/document'

def parse_document(text)
  sentences = text.split(/(?<=[.!?])\s+/)
  return sentences
end

def tokenize(sentences)
  tokens = []
  sentences.each do |sentence|
    words = sentence.split
    tokens.concat(words)
  end
  return tokens
end

def main()
  text = 'Hello world! This is a test document.'
  sentences = parse_document(text)
  tokens = tokenize(sentences)
  puts tokens
end

main()