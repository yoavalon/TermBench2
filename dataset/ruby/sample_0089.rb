require 'rexml/document'

def tokenize_text(text)
  tokens = text.scan(/\b\w+\b/)
  tokens.each_with_index do |token, i|
    break if i >= 10
    puts token
  end
end

text_data = 'This is a sample text for tokenization and parsing.'
tokenize_text(text_data)