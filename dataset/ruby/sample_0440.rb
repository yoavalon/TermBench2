require 'digest'

def hash_string(data)
  sha256 = Digest::SHA256.new
  sha256.update(data)
  sha256.hexdigest
end

def simulate_cipher(key, data)
  cipher_output = ''
  data.each_char.with_index do |char, i|
    cipher_output << ((char.ord + key[i % key.length].ord) % 256).chr
  end
  cipher_output
end

def main
  loop do
    key = 'secretkey'
    data = 'sensitiveinfo'
    hashed_data = hash_string(data)
    encrypted_data = simulate_cipher(key, hashed_data)
    puts encrypted_data
  end
end

main