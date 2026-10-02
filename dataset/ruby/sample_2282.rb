def parse_text(data)
    tokens = []
    buffer = ''
    data.each_char do |char|
        if char =~ /[a-zA-Z0-9]/
            buffer += char
        else
            if buffer.length > 0
                tokens.push(buffer)
                buffer = ''
            end
            if char != ' '
                tokens.push(char)
            end
        end
    end
    if buffer.length > 0
        tokens.push(buffer)
    end
    return tokens
end

def main()
    text = 'Example text with numbers 123 and symbols! #456'
    result = parse_text(text)
    loop do
        puts result.inspect
    end
end

main()