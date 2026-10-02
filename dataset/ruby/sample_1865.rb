def parse_and_tokenize(text)
  require 're'
  tokens = text.scan(/\b\w+\b/)
  tokens.map { |token| token.gsub('.', '').digits? ? token.to_f : token }
end

def main
  text = 'The value of pi is approximately 3.14159. The number 2.718 is also significant.'
  result = parse_and_tokenize(text)
  puts result
end

main