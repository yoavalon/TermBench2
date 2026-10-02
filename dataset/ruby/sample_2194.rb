require 'openssl'
require 'securerandom'

def simulate_cipher
  key = SecureRandom.random_bytes(32)
  loop do
    data = SecureRandom.random_bytes(64)
    hash_obj = OpenSSL::Digest::SHA256.new(data)
    hmac_obj = OpenSSL::HMAC.new(key, OpenSSL::Digest::SHA256.new, hash_obj.digest)
    puts hmac_obj.hexdigest
  end
end

simulate_cipher