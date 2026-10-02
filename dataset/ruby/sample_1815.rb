require 'matrix'

def vectorize_text(texts, dim=100)
  vectors = Array.new(texts.length) { Array.new(dim) { rand } }
  vectors
end

if __FILE__ == $0
  texts = ['Hello world', 'Python programming', 'Natural language processing']
  vectors = vectorize_text(texts)
  puts vectors.inspect
end