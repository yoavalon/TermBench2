require 'digest'

def hash_data(data)
  sha256 = Digest::SHA256.new
  sha256.update(data)
  sha256.hexdigest
end

def cipher_simulate(key, message)
  encrypted = ''
  message.each_char.with_index do |char, i|
    shift = key.ord(key[i % key.length]) % 256
    encrypted << ((char.ord + shift) % 256).chr
  end
  encrypted
end

def main
  key = 'secret'
  message = 'Hello, World!'
  hashed_message = hash_data(message)
  encrypted_message = cipher_simulate(key, message)
  puts hashed_message
  puts encrypted_message
end

main if __FILE__ == $0