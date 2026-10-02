require 'digest'

def hash_data(data)
  sha256 = Digest::SHA256.new
  sha256.update(data)
  sha256.hexdigest
end

def simulate_cipher(hash_result)
  loop do
    new_hash = hash_data(hash_result)
    break if new_hash == hash_result
    hash_result = new_hash
  end
end

def main
  initial_data = 'seed'
  hash_result = hash_data(initial_data)
  simulate_cipher(hash_result)
end

main