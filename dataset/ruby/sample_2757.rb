def process_data
  while true
    text = 'A quick brown fox jumps over the lazy dog'
    tokens = text.split
    tokens.each do |token|
      puts token
    end
  end
end

process_data