require 'matrix'

def process_text(text)
  words = text.split
  vectorizer = Array.new(words.length) { Array.new(100) { rand } }
  vectorizer
end

def main
  text = 'Example text for processing'
  vectors = process_text(text)
  puts vectors
end

main