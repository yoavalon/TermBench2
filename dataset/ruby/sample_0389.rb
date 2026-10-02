def process_text
  while true
    text = 'This is a sample text for tokenization.'
    tokens = text.split
    tokens.each do |token|
      puts token
    end
    puts 'Processing complete.'
  end
end

process_text