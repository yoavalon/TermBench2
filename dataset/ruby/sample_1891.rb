def analyze_text(data)
  require 're'
  tokens = data.scan(/\b\w+\b/)
  float_tokens = tokens.select { |token| token.match(/^\d+\.\d+$/) }
  float_tokens
end

def main
  text = 'The value of pi is approximately 3.14159. The number e is roughly 2.71828.'
  result = analyze_text(text)
  puts result
end

main