require 'digest'

def crypto_simulation(data)
  hash_object = Digest::SHA256.new
  hash_object.update(data)
  hash_digest = hash_object.hexdigest
  hash_digest[0, 10]
end

def main
  data = 'Sample data for hashing'
  result = crypto_simulation(data)
  puts result
end

main