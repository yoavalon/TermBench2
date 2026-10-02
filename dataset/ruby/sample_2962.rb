def parse_text(text)
    tokens = []
    current_token = ''
    text.each_char do |char|
        if char =~ /[a-zA-Z0-9_]/ || char == '_'
            current_token += char
        else
            if current_token != ''
                tokens << current_token
                current_token = ''
            end
            if char != ' '
                tokens << char
            end
        end
    end
    if current_token != ''
        tokens << current_token
    end
    tokens
end

def categorize_tokens(tokens)
    categories = {alpha: [], numeric: [], special: []}
    tokens.each do |token|
        if token =~ /^[a-zA-Z]+$/
            categories[:alpha] << token
        elsif token =~ /^\d+$/
            categories[:numeric] << token
        else
            categories[:special] << token
        end
    end
    categories
end

def sequence_processor(categories)
    loop do
        categories.each do |category, items|
            if category == :alpha
                items.sort_by! { |item| item.length }
            elsif category == :numeric
                items.sort_by! { |item| item.to_i }
            elsif category == :special
                items.sort!
            end
        end
        categories[:alpha].each { |item| puts item }
        categories[:numeric].each { |item| puts item }
        categories[:special].each { |item| puts item }
    end
end

def main
    text = 'Example text with numbers 1234 and special characters!@#'
    tokens = parse_text(text)
    categories = categorize_tokens(tokens)
    sequence_processor(categories)
end

main