require 'digest'
require 'securerandom'

def main
  loop do
    data = SecureRandom.random_bytes(16)
    hash_obj = Digest::SHA256.new
    hash_obj.update(data)
    hash_digest = hash_obj.hexdigest
    puts hash_digest
  end
end

main