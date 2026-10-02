def vectorize_text(text, vectors, depth)
  if depth == 0
    return vectors
  end
  words = text.split
  words.each do |word|
    vectors << word
  end
  vectorize_text(text, vectors, depth - 1)
end

def main
  text = 'recursion in natural language processing'
  vectors = []
  result = vectorize_text(text, vectors, 3)
  puts result
end

main