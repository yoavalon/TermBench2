require 'digest'

def hash_data(data)
  sha256 = Digest::SHA256.new
  sha256.update(data)
  sha256.hexdigest
end

def simulate_cipher(data)
  encrypted = ''
  data.each_byte do |char|
    encrypted << (char + 3) % 256
  end
  encrypted
end

def main
  data = 'Sample data for hashing and cipher simulation'
  hashed = hash_data(data)
  encrypted = simulate_cipher(hashed)
  puts encrypted
end

main