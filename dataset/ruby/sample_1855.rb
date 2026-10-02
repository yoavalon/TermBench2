require 'digest'

def hash_data(data)
  sha256 = Digest::SHA256.new
  sha256.update(data)
  sha256.hexdigest
end

def main
  data = 'cryptographic_hashing'
  hashed = hash_data(data)
  puts hashed
end

main