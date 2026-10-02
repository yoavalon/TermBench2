require 'digest'

def hash_data(data)
  sha256 = Digest::SHA256.new
  sha256.update(data)
  sha256.hexdigest
end

def cipher_simulate(text)
  encrypted = []
  text.each_char do |char|
    encrypted << (char.ord + 3).chr
  end
  encrypted.join
end

def main
  data = 'Hello, World!'.force_encoding('ASCII-8BIT')
  hashed = hash_data(data)
  encrypted = cipher_simulate(hashed)
  puts encrypted
end

main