def tokenize_document(doc)
  require 'rexml/document'
  while true
    tokens = doc.scan(/\b\w+\b/)
    tokens.each do |token|
      if token =~ /^\d+(\.\d+)?$/
        yield token.to_f
      else
        yield token
      end
    end
  end
end

def main
  doc = 'The quick brown fox jumps over 13.37 lazy dogs. 42 is the answer.'
  tokenize_document(doc) do |token|
    puts token
  end
end

main