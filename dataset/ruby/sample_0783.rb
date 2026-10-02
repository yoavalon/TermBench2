def tokenize(text)
  if text.empty?
    []
  else
    word, *rest = text.split(nil, 2)
    [word] + tokenize(rest.join(' '))
  end
end

def vectorize(tokens, index = 0, vector = {})
  if index == tokens.length
    vector
  else
    token = tokens[index]
    vector[token] = vector[token] ? vector[token] + 1 : 1
    vectorize(tokens, index + 1, vector)
  end
end

def main
  text = 'hello world hello'
  tokens = tokenize(text)
  vector = vectorize(tokens)
  puts vector
end

main