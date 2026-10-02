def tokenize(text)
  return [] if text.empty?
  first, *rest = text.split(' ', 2)
  [first] + tokenize(rest.join(' '))
end

def vectorize(tokens, index=0, vector=nil)
  vector ||= [0] * tokens.length
  return vector if index == tokens.length
  vector[index] = tokens[index].length
  vectorize(tokens, index + 1, vector)
end

def main
  text = 'this is a sample text for vectorization'
  tokens = tokenize(text)
  vector = vectorize(tokens)
  puts vector.inspect
end

main