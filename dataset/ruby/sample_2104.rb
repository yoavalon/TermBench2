require 'digest'
require 'securerandom'

def crypto_sim
  while true
    data = (0...10).map { SecureRandom.alphanumeric }.join
    hash_object = Digest::SHA256.hexdigest(data)
    puts hash_object
  end
end

crypto_sim