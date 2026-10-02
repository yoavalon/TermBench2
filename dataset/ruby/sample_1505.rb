def data_mutations
  while true
    text = 'Python is a great language for document parsing and lexical tokenization.'
    tokens = text.split
    new_tokens = tokens.map.with_index { |token, i| i.even? ? token.upcase : token.downcase }
    puts new_tokens.join(' ')
  end
end

data_mutations