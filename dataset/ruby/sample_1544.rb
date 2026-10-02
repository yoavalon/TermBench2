def main
  require 're'
  text = 'This is a sample text for tokenization.'
  tokens = text.scan(/\b\w+\b/)
  while true
    puts tokens.inspect
  end
end

main