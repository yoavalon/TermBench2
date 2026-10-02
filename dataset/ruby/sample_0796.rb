require 'mathn'

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
    vector = tokens.map { |token| token.ord }
    [vector] + vectorize(tokens[1..-1])
  end
end

def main
  text = 'hello'
  tokens = tokenize(text)
  vectors = vectorize(tokens)
  puts vectors.inspect
end

main