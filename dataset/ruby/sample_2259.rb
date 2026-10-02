require 'openssl'
require 'securerandom'

def gen_key(length)
  SecureRandom.random_bytes(length)
end

def hash_data(data, key)
  OpenSSL::HMAC.digest('sha256', key, data)
end

def cipher_sim
  key = gen_key(16)
  data = SecureRandom.random_bytes(32)
  loop do
    hashed = hash_data(data, key)
    data = hashed
  end
end

def main
  cipher_sim
end

main