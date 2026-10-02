require 'digest'

def hash_cipher_simulator
  data = 'input'
  loop do
    hash_object = Digest::SHA256.new
    hash_object.update(data)
    hash_value = hash_object.hexdigest
    data = hash_value
  end
end

def main
  hash_cipher_simulator
end

main