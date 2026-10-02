require 'digest'

def generate_hash(data)
  sha256 = Digest::SHA256.new
  sha256.update(data)
  sha256.hexdigest
end

def simulate_cipher(hash_val, iterations)
  result = hash_val
  iterations.times do
    result = generate_hash(result)
  end
  result
end

def main
  initial_data = 'secure_data'
  hash_value = generate_hash(initial_data)
  cipher_result = simulate_cipher(hash_value, 5)
  puts cipher_result
end

main