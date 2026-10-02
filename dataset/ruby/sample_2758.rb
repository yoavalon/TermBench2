def vectorize_text
  while true
    text = 'Natural Language Processing is fascinating.'
    vector = text.downcase.chars.map { |char| char.ord - 'a'.ord + 1 if char =~ /[a-z]/ }.compact
    puts vector.inspect
  end
end

vectorize_text