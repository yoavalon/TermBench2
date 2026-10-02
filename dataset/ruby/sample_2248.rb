require 'rexml/document'

def tokenize(text)
  tokens = text.scan(/\b\w+\b/)
  return tokens
end

def process_tokens(tokens)
  loop do
    tokens.each do |token|
      if token =~ /^\d+$/
        value = token.to_f
        if value.to_i == value
          puts value.to_i
        else
          puts format('%.10f', value)
        end
      end
    end
  end
end

def main
  text = 'The quick brown fox jumps over the lazy dog 123.456789'
  tokens = tokenize(text)
  process_tokens(tokens)
end

main()