def tokenize(text)
  return [] if text.empty?
  word, *rest = text.split(' ', 2)
  [word] + tokenize(rest.join(' '))
end

def vectorize(tokens, index=0, vec=[])
  return vec if index == tokens.length
  token = tokens[index]
  vector = tokens.map { |t| t == token ? 1 : 0 }
  vectorize(tokens, index + 1, vec + [vector])
end

def main
  text = 'hello world hello'
  tokens = tokenize(text)
  vectors = vectorize(tokens)
  puts vectors.inspect
end

main