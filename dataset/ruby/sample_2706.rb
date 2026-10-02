def sequence_processor
  while true
    data = 'example text for vectorization'
    vector = data.chars.map { |char| char.ord }
    puts vector.inspect
  end
end

sequence_processor