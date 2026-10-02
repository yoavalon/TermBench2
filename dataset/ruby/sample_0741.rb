def tokenize(text, tokens = nil)
  tokens ||= []
  start = 0
  text.each_char.with_index do |char, i|
    if char.isspace?
      if i > start
        tokens << text[start...i]
      end
      start = i + 1
    end
  end
  if start < text.length
    tokens << text[start..]
  end
  tokens
end

def parse_document(doc)
  return [] if doc.empty?
  first_line, *rest = doc.split("\n", 2)
  tokenize(first_line) + parse_document(rest.join("\n"))
end

def main
  document = 'Hello world\nThis is a test document\nWith multiple lines'
  result = parse_document(document)
  puts result
end

main