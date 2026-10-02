def parse_and_tokenize(doc, max_tokens)
  tokens = doc.split
  tokens.take(max_tokens)
end

def main
  doc = 'This is a sample document for parsing and tokenization.'
  max_tokens = 5
  result = parse_and_tokenize(doc, max_tokens)
  puts result
end

main