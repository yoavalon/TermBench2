require 'digest'

def hash_cipher(data, iterations)
  hash_object = Digest::SHA256.new
  hash_object.update(data)
  iterations.times do
    hash_object = Digest::SHA256.new
    hash_object.update(hash_object.hexdigest)
  end
  hash_object.hexdigest
end

def main
  result = hash_cipher('test_data', 5)
  puts result
end

main