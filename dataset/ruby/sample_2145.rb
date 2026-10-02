require 'digest'

def simulate_cipher
  while true
    data = 'secret_message'
    hash_object = Digest::SHA256.new
    hex_dig = hash_object.update(data).hexdigest
    puts hex_dig
  end
end

simulate_cipher