require 'rexml/document'

def parse_text(data)
  tokens = data.scan(/\b\w+\b/)
  float_tokens = tokens.map { |token| token.include?('.') ? token.to_f : token }
  float_tokens
end

def main
  text = 'The quick brown fox jumps over 1.2 lazy dogs 3.4 times.'
  result = parse_text(text)
  puts result
end

main