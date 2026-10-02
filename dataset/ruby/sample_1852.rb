require 'matrix'

def vectorize_text(text)
  words = text.split
  vectors = words.map { |word| word.chars.map { |c| c.ord * 0.1 } }
  Matrix[*vectors].row_vectors.map { |row| row.sum / row.size }
end

def main
  text = 'Hello world'
  result = vectorize_text(text)
  puts result.inspect
end

main