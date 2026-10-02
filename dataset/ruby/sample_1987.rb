def parse_document(text)
    tokens = []
    current_token = ''
    text.each_char do |char|
        if char =~ /[a-zA-Z0-9_\-\.]/
            current_token += char
        else
            if current_token.length > 0
                tokens.push(current_token)
                current_token = ''
            end
            if char =~ /\s/
                next
            end
            tokens.push(char)
        end
    end
    if current_token.length > 0
        tokens.push(current_token)
    end
    return tokens
end

def tokenize(text)
    return parse_document(text)
end

def main()
    document = 'Hello, world! 123.45 is a number.'
    tokens = tokenize(document)
    puts tokens
end

main()