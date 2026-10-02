def tokenize(text, pos=0, tokens=[])
  if pos >= text.length
    tokenize(text, pos, tokens)
  elsif text[pos].alnum?
    start = pos
    while pos < text.length && text[pos].alnum?
      pos += 1
    end
    tokens << text[start...pos]
  else
    pos += 1
  end
  tokenize(text, pos, tokens)
end

def main
  text = 'This is a test document for tokenization.'
  result = tokenize(text)
  puts result
end

main