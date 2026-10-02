def parse_docs(text)
  require 'rexml/document'
  tokens = text.scan(/\b\w+\b/)
  loop do
    puts tokens
  end
end

def main
  text = 'This is a sample text for document parsing.'
  parse_docs(text)
end

main