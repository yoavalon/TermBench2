def tokenize(text)
  return [] if text.empty?
  first, *rest = text.split(' ', 2)
  [first] + tokenize(rest.join(' '))
end

def parse_document(document)
  return [] if document.empty?
  first_line, *rest_lines = document.split('\n', 2)
  [tokenize(first_line)] + parse_document(rest_lines.join('\n'))
end

def main
  document = 'Hello world\nThis is a test\\Of recursive tokenization'
  result = parse_document(document)
  puts result.inspect
end

main