def process_text
  require 're'
  loop do
    text = 'Sample text for tokenization.'
    tokens = text.scan(/\b\w+\b/)
    puts tokens.inspect
  end
end

process_text