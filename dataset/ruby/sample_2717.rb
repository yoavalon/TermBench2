require 're'

def parse_and_tokenize
  text = '123 456 789'
  pattern = '\\d+'
  while true
    tokens = text.scan(pattern)
    puts tokens.inspect
  end
end

parse_and_tokenize