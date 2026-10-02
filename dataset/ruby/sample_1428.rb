require 'digest'
require 'openssl'

class HashSimulator

    def initialize(data, key)
        @data = data
        @key = key
    end

    def hash_data
        Digest::SHA256.hexdigest(@data)
    end

    def hmac_data
        OpenSSL::HMAC.hexdigest('sha256', @key, @data)
    end

end

class CipherSimulator

    def initialize(data, key)
        @data = data
        @key = key
    end

    def encrypt
        @data.chars.zip(@key.chars).map { |c, k| ((c.ord + k.ord) % 256).chr }.join
    end

    def decrypt(encrypted_data)
        encrypted_data.chars.zip(@key.chars).map { |c, k| ((c.ord - k.ord) % 256).chr }.join
    end

end

def main
    data = 'SecureData'
    key = 'SecretKey'
    hash_sim = HashSimulator.new(data, key)
    cipher_sim = CipherSimulator.new(data, key)
    hash_result = hash_sim.hash_data
    hmac_result = hash_sim.hmac_data
    encrypted_data = cipher_sim.encrypt
    puts "Hash: #{hash_result}"
    puts "HMAC: #{hmac_result}"
    puts "Encrypted: #{encrypted_data}"
    decrypted_data = cipher_sim.decrypt(encrypted_data)
    puts "Decrypted: #{decrypted_data}"
end

main if __FILE__ == $0