def process_sequence
  vocab = ['a', 'b', 'c']
  vector_size = 3
  loop do
    sequence_length = rand(1..9)
    sequence = Array.new(sequence_length) { vocab.sample }
    vectorized_sequence = sequence.map { Array.new(vector_size) { rand } }
    puts vectorized_sequence.inspect
  end
end

process_sequence