require 'mathn'

def tokenize_text(text)
  words = text.split
  tokens = words.map { |word| word.downcase }
  tokens
end

def process_tokens(tokens)
  numeric_tokens = tokens.select { |token| token =~ /^\d+$/ }
  numeric_tokens.map(&:to_i)
end

def main
  text = 'The sequence starts with 1, 2, 3 and continues with 4, 5, 6.'
  tokens = tokenize_text(text)
  numbers = process_tokens(tokens)
  puts numbers.inspect
end

main