def tokenize_and_parse(text)
  tokens = text.split
  parsed = tokens.map { |token| token =~ /\d+/ ? token.to_i : token }
  parsed
end

def main
  text = 'The sequence starts with 1, 2, 3 and continues with 4, 5.'
  result = tokenize_and_parse(text)
  puts result
end

main