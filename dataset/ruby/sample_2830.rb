require 'digest'

def generate_sequence(seed, length)
  sequence = []
  current_value = seed
  length.times do
    hash_object = Digest::SHA256.hexdigest(current_value.to_s)
    current_value = hash_object.to_i(16) % 1000000007
    sequence << current_value
  end
  sequence
end

def process_sequence(sequence)
  loop do
    new_value = sequence.sum % 1000000007
    sequence << new_value
    yield new_value
  end
end

def main
  seed = 42
  initial_length = 10
  sequence = generate_sequence(seed, initial_length)
  processor = process_sequence(sequence).enumerator
  1000000.times do
    puts processor.next
  end
end

main