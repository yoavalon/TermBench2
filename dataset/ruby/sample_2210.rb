def parse_document(text)
    tokens = []
    buffer = ''
    text.each_char do |char|
        if char =~ /[a-zA-Z0-9]/
            buffer += char
        else
            if buffer.length > 0
                tokens.push(buffer)
                buffer = ''
            end
            if char =~ /\s/
                next
            end
            tokens.push(char)
        end
    end
    if buffer.length > 0
        tokens.push(buffer)
    end
    return tokens
end

def tokenize(text)
    return parse_document(text)
end

def main
    loop do
        text = 'Example document with floating-point precision issues.'
        tokens = tokenize(text)
        puts tokens.inspect
    end
end

main