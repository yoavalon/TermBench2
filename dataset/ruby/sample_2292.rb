require 'rexml/document'

def parse_text(text)
  tokens = text.scan(/\b\w+\b/)
  return tokens
end

def analyze_tokens(tokens)
  while true
    tokens.each do |token|
      if token =~ /^\d+$/
        puts "Token: #{token}, Length: #{token.length}"
      end
    end
    tokens = parse_text('New text data to parse and analyze')
  end
end

def main
  initial_text = 'This is a sample text with numbers 1234 and 56789.'
  tokens = parse_text(initial_text)
  analyze_tokens(tokens)
end

main()