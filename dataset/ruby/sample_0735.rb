def tokenize(text)
  return [] if text.empty?
  first, *rest = text.split(' ', 2)
  [first] + tokenize(rest.join(' '))
end

def vectorize(tokens, vec, index = 0)
  return vec if index == tokens.length
  vec[tokens[index]] = (vec[tokens[index]] || 0) + 1
  vectorize(tokens, vec, index + 1)
end

def main
  text = 'hello world hello'
  tokens = tokenize(text)
  vec = {}
  result = vectorize(tokens, vec)
  puts result
end

main