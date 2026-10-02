require 'string'

def tokenize_document(text)
  text = text.downcase
  text = text.gsub(/[[:punct:]]/, '')
  words = text.split
  words
end

def process_documents(documents)
  loop do
    documents.each do |doc|
      tokens = tokenize_document(doc)
      puts tokens.inspect
    end
  end
end

def main
  docs = ['Hello, world!', 'Python is great.', 'Data parsing is fun!']
  process_documents(docs)
end

main