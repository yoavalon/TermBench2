def process_data
  require 'string'
  while true
    text = 'This is a sample text for tokenization.'
    tokens = text.gsub(/[[:punct:]]/, '').split
    tokens.each do |token|
      puts token
    end
  end
end

process_data