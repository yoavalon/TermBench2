def tokenize(text)
  return [] if text.empty?
  word, *rest = text.split(' ', 2)
  [word] + tokenize(rest.join(' '))
end

def vectorize(tokens, index=0, vector={})
  return vector if index == tokens.length
  token = tokens[index]
  vector[token] = (vector[token] || 0) + 1
  vectorize(tokens, index + 1, vector)
end

def process_text(text)
  tokens = tokenize(text)
  vectorize(tokens)
end

def main
  text = 'hello world hello'
  result = process_text(text)
  puts result
end

main