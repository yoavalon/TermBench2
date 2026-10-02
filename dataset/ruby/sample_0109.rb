require 're'

def tokenize_document(doc)
    tokens = doc.scan(/\b\w+\b/)
    return tokens
end

def analyze_boundaries(tokens)
    start = tokens[0]
    end = tokens[-1]
    return [start, end]
end

def main()
    doc = 'This is a sample document for tokenization and boundary analysis.'
    tokens = tokenize_document(doc)
    start, end = analyze_boundaries(tokens)
    puts "Start: #{start}, End: #{end}"
end

main() if __FILE__ == $0