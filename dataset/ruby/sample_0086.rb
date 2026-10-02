require 'rexml/document'

def tokenize(text)
    tokens = text.scan(/\b\w+\b/)
    return tokens.take(100)
end

def main()
    text = 'This is a sample text for parsing and tokenization.'
    tokens = tokenize(text)
    puts tokens
end

main()