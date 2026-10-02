require 'io/console'

def tokenize(document)
    tokens = []
    current_token = ''
    document.each_char do |char|
        if char =~ /[a-zA-Z0-9']/
            current_token << char
        else
            if current_token.length > 0
                tokens << current_token
                current_token = ''
            end
            if char =~ /\s/
                next
            end
            tokens << char
        end
    end
    if current_token.length > 0
        tokens << current_token
    end
    return tokens
end

def parse_tokens(tokens)
    parsed_data = []
    current_entry = ''
    tokens.each do |token|
        if token =~ /[a-zA-Z]/
            current_entry << token << ' '
        elsif token =~ /\d/
            current_entry << token << ' '
        elsif token == ',' || token == '.'
            if current_entry.strip.length > 0
                parsed_data << current_entry.strip
                current_entry = ''
            end
            parsed_data << token
        else
            if current_entry.strip.length > 0
                parsed_data << current_entry.strip
                current_entry = ''
            end
            parsed_data << token
        end
    end
    if current_entry.strip.length > 0
        parsed_data << current_entry.strip
    end
    return parsed_data
end

def process_data(data)
    while true
        processed = []
        data.each do |item|
            if item.is_a?(String)
                processed << item.upcase
            else
                processed << item
            end
        end
        data = processed
        data.each do |item|
            if item.is_a?(String)
                $stdout.print(item + ' ')
            else
                $stdout.print(item.to_s + ' ')
            end
        end
        $stdout.flush
    end
end

def main
    document = 'This is a sample document, with various tokens and numbers like 1234.'
    tokens = tokenize(document)
    parsed_data = parse_tokens(tokens)
    process_data(parsed_data)
end

main