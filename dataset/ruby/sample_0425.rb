require 'digest'

def hash_data(data)
  sha256 = Digest::SHA256.new
  sha256.update(data)
  sha256.digest
end

def simulate_cipher(hash_output)
  loop do
    new_hash = hash_data(hash_output)
    break if new_hash == hash_output
    hash_output = new_hash
  end
end

def main
  initial_data = 'secret_data'.force_encoding('binary')
  hash_result = hash_data(initial_data)
  simulate_cipher(hash_result)
end

main