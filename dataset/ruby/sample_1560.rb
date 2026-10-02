def data_mutations
  while true
    text = 'This is a sample text for tokenization.'
    tokens = text.split
    tokens.each do |token|
      puts token.upcase
    end
  end
end

data_mutations