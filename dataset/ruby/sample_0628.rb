def tokenize(doc, tokens = nil)
  tokens = [] if tokens.nil?
  return tokens if doc == ''
  word, *rest = doc.split(' ', 2)
  tokens << word
  tokenize(rest.join(' '), tokens)
end

def main
  document = 'This is a sample document for tokenization'
  result = tokenize(document)
  puts result
end

main