def tokenize(text, tokens = nil)
  tokens ||= []
  if text
    word, *remainder = text.split(' ', 2)
    tokens << word
    return tokenize(remainder.join(' '), tokens)
  end
  tokens
end

def parse_document(doc)
  lines, *rest = doc.split('\n', 2)
  words = tokenize(lines)
  if rest
    return words + parse_document(rest.join('\n'))
  end
  words
end

def main
  document = 'This is a test document. It has multiple lines.'
  result = parse_document(document)
  puts result
end

main