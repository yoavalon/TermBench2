def tokenize(text, depth)
  return [] if depth == 0
  words = text.split
  result = []
  words.each do |word|
    result << word
    result << tokenize(word, depth - 1)
  end
  result
end

def vectorize(tokens, depth)
  return [] if depth == 0
  vector = [tokens.length]
  tokens.each do |token|
    vector << vectorize(token, depth - 1)
  end
  vector
end

def main
  text = 'Recursive vectorization'
  depth = 2
  tokens = tokenize(text, depth)
  vector = vectorize(tokens, depth)
  puts vector
end

main