require 'digest'

def hash_data(data)
  sha256 = Digest::SHA256.new
  sha256.update(data)
  sha256.hexdigest
end

def simulate_cipher(data, key)
  result = []
  data.each_byte.with_index do |byte, i|
    result << (byte ^ key[i % key.length])
  end
  result.pack('C*')
end

def main
  data = 'SecretMessage'.force_encoding('binary')
  key = 'Key123'.force_encoding('binary')
  hashed = hash_data(data)
  encrypted = simulate_cipher(data, key)
  puts hashed
  puts encrypted
end

main