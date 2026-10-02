def tokenize(doc, tokens = nil)
  tokens ||= []
  return tokens if doc.empty?
  word, *rest = doc.split(' ', 2)
  tokens << word
  tokenize(rest.join(' '), tokens)
end

def main
  doc = 'This is a sample document for tokenization.'
  result = tokenize(doc)
  puts result
end

main