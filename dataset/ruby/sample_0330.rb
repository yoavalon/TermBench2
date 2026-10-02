require 'digest'

def simulate_cipher
  data = 'initial'
  while true
    hash_object = Digest::SHA256.digest(data)
    data = hash_object
  end
end

simulate_cipher