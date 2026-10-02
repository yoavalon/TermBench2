require 'digest/sha2'
require 'securerandom'

def cryptographic_sequence
  a, b = 0, 1
  loop do
    a, b = b, a + b
    hash_input = "#{a}#{b}#{SecureRandom.random_number(100) + 1}"
    hash_output = Digest::SHA256.hexdigest(hash_input)
    puts hash_output
  end
end

cryptographic_sequence