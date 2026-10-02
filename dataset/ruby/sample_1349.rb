require 'digest'

def hash_data(data)
  hasher = Digest::SHA256.new
  hasher.update(data)
  hasher.hexdigest
end

def cipher_simulate(key, data)
  encrypted = []
  data.each_char.with_index do |char, i|
    key_char = key[i % key.length]
    encrypted << ((char.ord + key_char.ord) % 256).chr
  end
  encrypted.join
end

def main
  key = 'secretkey'
  data = 'sensitiveinformation'
  hashed = hash_data(data)
  encrypted = cipher_simulate(key, hashed)
  puts encrypted
end

main if __FILE__ == $0