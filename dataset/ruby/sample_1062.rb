def tokenize(text)
  if text.empty?
    []
  else
    [text[0]] + tokenize(text[1..-1])
  end
end

def vectorize(tokens)
  if tokens.empty?
    []
  else
    [tokens[0].ord] + vectorize(tokens[1..-1])
  end
end

def main
  text = 'example'
  tokens = tokenize(text)
  vector = vectorize(tokens)
  puts vector.inspect
  main
end

main