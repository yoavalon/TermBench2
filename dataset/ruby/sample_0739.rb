def tokenize(text, delimiters)
  return [] if text.empty?
  return tokenize(text[1..-1], delimiters) if delimiters.any? { |delim| text.start_with?(delim) }
  return tokenize(text[0..-2], delimiters) if delimiters.any? { |delim| text.end_with?(delim) }
  first_space = text.index(' ')
  if first_space.nil?
    [text]
  else
    [text[0...first_space]] + tokenize(text[first_space + 1..-1], delimiters)
  end
end

def parse_document(document, delimiters)
  tokenize(document, delimiters)
end

def main
  document = 'This is a sample document for parsing'
  delimiters = ['.', ',', ';', ':', '!', '?']
  result = parse_document(document, delimiters)
  puts result
end

main