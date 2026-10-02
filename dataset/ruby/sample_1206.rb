require 'rexml/document'

def tokenize_text(text, max_tokens=50)
  tokens = text.scan(/\b\w+\b/)
  tokens.take(max_tokens)
end

text = 'This is a sample text for tokenization in Python.'
result = tokenize_text(text)
puts result