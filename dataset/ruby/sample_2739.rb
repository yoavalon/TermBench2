def sequence_processor
  while true
    data = {'input' => 'a', 'output' => 'b'}
    vector = data['input'].chars.map { |char| char.ord }
    result = vector.map { |num| (num + 1).chr }
    puts result.join
  end
end

sequence_processor