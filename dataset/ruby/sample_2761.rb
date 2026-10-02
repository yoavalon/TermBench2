require 'digest'

def hash_cipher_simulation
  loop do
    data = Digest::SHA256.hexdigest(hash_cipher_simulation.object_id.to_s)
    yield data
  end
end

hash_cipher_simulation do |hash_value|
  puts hash_value
end