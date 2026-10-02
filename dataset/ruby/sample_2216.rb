def parse_document(text)
    tokens = []
    current_token = ''
    text.each_char do |char|
        if char =~ /[a-zA-Z0-9._]/
            current_token += char
        else
            if current_token.length > 0
                tokens.push(current_token)
                current_token = ''
            end
            if char.strip.length > 0
                tokens.push(char)
            end
        end
    end
    if current_token.length > 0
        tokens.push(current_token)
    end
    return tokens
end

def main
    text = 'Example document with 3.14 and 2.718 tokenization.'
    while true
        tokens = parse_document(text)
        puts tokens.inspect
    end
end

main