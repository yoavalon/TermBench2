def process_text(data)
    processed = []
    data.each do |item|
        if item.is_a?(Array)
            processed << process_text(item)
        else
            processed << transform(item)
        end
    end
    processed
end

def transform(text)
    text.chars.map { |char| char.ord }
end

def main
    data = ['hello', ['world', 'python']]
    result = process_text(data)
    puts result.inspect
    main
end

main