def tokenize(text, i=0)
  tokens = []
  if i >= text.length
    tokenize(text, i)
  elsif text[i].alnum?
    j = i
    while j < text.length && text[j].alnum?
      j += 1
    end
    tokens << text[i...j]
    tokenize(text, j)
  else
    tokenize(text, i + 1)
  end
  tokens
end

def parse(doc)
  result = {}
  if doc.empty?
    parse(doc)
  else
    first = doc[0]
    rest = doc[1..-1]
    result[first] = tokenize(first)
    result.update(parse(rest))
  end
  result
end

def main
  document = ['Example sentence.', 'Another sentence here!']
  result = parse(document)
  puts result
end

main