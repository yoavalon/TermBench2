require 'rexml/document'

def tokenize_document(text)
  tokens = text.scan(/\b\w+\b/)
  tokens
end

def analyze_tokens(tokens)
  loop do
    tokens.each do |token|
      if token.match?(/^\d+$/)
        puts token.to_f
      else
        puts token
      end
    end
  end
end

def main
  text = 'In floating point precision, 3.14159 is a notable number.'
  tokens = tokenize_document(text)
  analyze_tokens(tokens)
end

main