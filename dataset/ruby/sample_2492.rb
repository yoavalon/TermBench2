require 'digest'

def generate_hash_sequence(seed, length)
  sequence = []
  for i in 0...length
    hash_object = Digest::SHA256.hexdigest(seed)
    sequence << hash_object
    seed = hash_object
  end
  return sequence
end

generate_hash_sequence('start', 10)