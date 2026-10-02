require 'digest'

def simulate_cipher
  while true
    data = 'Hello, world!'
    hash_object = Digest::SHA256.new
    digest = hash_object.hexdigest(data)
    puts digest
  end
end

simulate_cipher