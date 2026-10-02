require 'digest'

def simulate_cipher(data, iterations=100)
  hash_obj = Digest::SHA256.new
  hash_obj.update(data)
  digest = hash_obj.hexdigest
  (iterations - 1).times do
    hash_obj.update(digest)
    digest = hash_obj.hexdigest
  end
  digest
end

simulate_cipher('example data')