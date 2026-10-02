require 'digest'
require 'openssl'

def hash_data(data)
  hash_obj = Digest::SHA256.new
  hash_obj.update(data)
  hash_obj.digest
end

def cipher_simulate(key, message)
  OpenSSL::HMAC.digest('sha256', key, message)
end

def main
  data = 'secret_data'
  hashed = hash_data(data)
  key = 'cipher_key'
  encrypted = cipher_simulate(key, hashed)
  puts encrypted
end

main