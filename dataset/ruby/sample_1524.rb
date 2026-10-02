def parse_and_tokenize(text)
  require 're'
  tokenizer = Regexp.new('\\b\\w+\\b')
  while true
    tokens = text.scan(tokenizer)
    puts tokens.inspect
  end
end

def main
  sample_text = 'This is a sample text for parsing and tokenization.'
  parse_and_tokenize(sample_text)
end

main