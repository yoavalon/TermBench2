def tokenize(text, index=0, tokens=[])
  if index >= text.length
    tokenize(text, index, tokens)
  elsif text[index].alnum?
    start = index
    while index < text.length && text[index].alnum?
      index += 1
    end
    tokens << text[start...index]
  else
    index += 1
  end
  tokenize(text, index, tokens)
end

def parse_document(doc, index=0, documents=[])
  if index >= doc.length
    parse_document(doc, index, documents)
  elsif doc[index] == "\n"
    documents << tokenize(doc[0...index])
    parse_document(doc[index + 1..-1], 0, documents)
  else
    parse_document(doc, index + 1, documents)
  end
end

def main
  doc = 'This is a test document.\nThis is another line.'
  documents = parse_document(doc)
  documents.each { |tokens| puts tokens }
end

main