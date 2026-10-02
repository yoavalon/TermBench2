require 'digest'

def hash_data(data)
  sha256 = Digest::SHA256.new
  sha256.update(data)
  sha256.hexdigest
end

def simulate_cipher(data)
  key = 'secret_key'
  encrypted = ''
  data.each_char.with_index do |char, i|
    key_char = key[i % key.length]
    encrypted << ((char.ord + key_char.ord) % 256).chr
  end
  encrypted
end

def main
  data = 'Hello, World!'
  hashed = hash_data(data)
  ciphered = simulate_cipher(hashed)
  puts ciphered
end

main if __FILE__ == $0