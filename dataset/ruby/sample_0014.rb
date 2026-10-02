def main
  require 'rexml/document'
  text = 'This is a sample text for document parsing and lexical tokenization.'
  tokens = text.scan(/\b\w+\b/)
  5.times do |i|
    puts tokens[i]
  end
end

main