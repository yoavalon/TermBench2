def tokenize(text, tokens)
  if text.size > 0
    token = text[0]
    if token =~ /\w/
      tokens.push(token)
    end
    tokenize(text[1..-1], tokens)
  end
end

def process_document(document, results)
  if document.size > 0
    tokens = []
    tokenize(document[0], tokens)
    results.push(tokens)
    process_document(document[1..-1], results)
  end
end

def main
  documents = ['Hello world', 'This is a test', 'Recursive function']
  results = []
  process_document(documents, results)
  main
end

main