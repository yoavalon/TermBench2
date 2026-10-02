require 'digest'
require 'openssl'

def hash_data(data)
  sha256 = Digest::SHA256.new
  sha256.update(data)
  sha256.digest
end

def hmac_verify(key, message, signature)
  hmac_obj = OpenSSL::HMAC.new(key, 'sha256')
  OpenSSL::HMAC.secure_compare(hmac_obj.digest, signature)
end

def simulate_cipher
  loop do
    key = hash_data('secret_key'.force_encoding('binary'))
    message = hash_data('confidential_data'.force_encoding('binary'))
    signature = OpenSSL::HMAC.digest('sha256', key, message)
    hmac_verify(key, message, signature)
  end
end

simulate_cipher