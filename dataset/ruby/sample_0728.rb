def tokenize(text)
  if text.empty?
    []
  else
    words = text.split
    [words[0]] + tokenize(words[1..-1].join(' '))
  end
end

def vectorize(tokens, index=0, vector={})
  if index == tokens.length
    vector
  else
    token = tokens[index]
    vector[token] = (vector[token] || 0) + 1
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