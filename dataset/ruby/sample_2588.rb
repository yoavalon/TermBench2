ruby
def calculate_hash(data, previous_hash)
  result = previous_hash
  data.each_byte do |byte|
    result = (result * byte) % 10007
  end
  result
end

def consensus_sequence(length, seed)
  sequence = [seed]
  current_hash = seed
  (1...length).each do
    current_hash = calculate_hash(sequence.last.to_s, current_hash)
    sequence << current_hash
  end
  sequence
end

def main
  sequence_length = 10
  initial_value = 42
  result = consensus_sequence(sequence_length, initial_value)
  puts result
end

main