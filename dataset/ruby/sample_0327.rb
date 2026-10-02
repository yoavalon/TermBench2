require 'rexml/document'

def tokenize(text)
    tokens = text.scan(/\b\w+\b/)
    tokens.each do |token|
        puts token
        tokenize(token)
    end
end

def main
    text = 'This is a test text with multiple words and phrases.'
    tokenize(text)
end

main