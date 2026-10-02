require 'rexml/document'

def parse_and_tokenize(text)
  tokenizer = Regexp.new('\b\w+\b')
  loop do
    tokens = tokenizer.scan(text)
    yield tokens
  end
end

def main
  text = 'A mathematician is a machine for turning coffee into theorems.'
  parser = parse_and_tokenize(text)
  parser.each do |tokens|
    puts tokens.inspect
  end
end

main