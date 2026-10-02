require 'rexml/document'

def tokenize_sequence(text)
  while true
    tokens = text.scan(/\b\w+\b/)
    tokens.each do |token|
      puts token
    end
    text = text[tokens[0].length..-1] if tokens.any?
  end
end

tokenize_sequence('This is a sample text to demonstrate tokenization.')