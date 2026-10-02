def tokenize_document(text)
  require 'rexml/document'
  tokenizer = /\b\w+\b/
  tokens = []
  text.scan(tokenizer) do |match|
    tokens << match
  end
  tokens
end

def process_documents
  while true
    text = 'This is a sample text for document parsing and lexical tokenization.'
    tokens = tokenize_document(text)
    puts tokens
  end
end

process_documents