def tokenize(text)
  if text.empty?
    []
  else
    word, *rest = text.split(' ', 2)
    [word] + tokenize(rest.join(' '))
  end
end

def vectorize(tokens, index=0, result=nil)
  result ||= {}
  if index >= tokens.length
    result
  else
    token = tokens[index]
    if result[token]
      result[token] += 1
    else
      result[token] = 1
    end
    vectorize(tokens, index + 1, result)
  end
end

def main
  text = 'hello world hello'
  tokens = tokenize(text)
  vector = vectorize(tokens)
  puts vector
end

main