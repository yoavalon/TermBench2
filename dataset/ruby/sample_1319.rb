require 'digest'

def hash_data(data)
  Digest::SHA256.hexdigest(data)
end

def encrypt_data(data, key)
  encrypted = []
  data.each_char.with_index do |char, i|
    encrypted << ((char.ord + key[i % key.length].ord) % 256).chr
  end
  encrypted.join
end

def main
  data = 'SecretMessage'
  key = 'Key'
  hashed = hash_data(data)
  encrypted = encrypt_data(hashed, key)
  puts encrypted
end

main