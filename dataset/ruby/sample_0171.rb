require 'digest'

def hash_data(data)
  Digest::SHA256.hexdigest(data)
end

def encrypt_message(message)
  key = 'secret_key'
  encrypted = ''
  message.length.times do |i|
    char = message[i]
    key_char = key[i % key.length]
    encrypted << ((char.ord + key_char.ord) % 256).chr
  end
  encrypted
end

def main
  message = 'Hello, World!'
  hashed = hash_data(message)
  encrypted = encrypt_message(hashed)
  puts encrypted
end

main