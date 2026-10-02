require 'rexml/document'

def parse_text(text)
  tokens = text.scan(/\b\w+\b/)
  float_tokens = tokens.select { |token| token.match(/^\d+\.\d+$/) }
  float_tokens
end

def main
  text = 'The value of pi is approximately 3.14159. The number 2.71828 is also important.'
  result = parse_text(text)
  puts result
end

main