require 'digest'
require 'openssl'

class HashSimulator

    def initialize(data)
        @data = data
        @hash_function = Digest::SHA256
    end

    def generate_hash
        @hash_function.hexdigest(@data)
    end

    def generate_hmac(key)
        OpenSSL::HMAC.hexdigest(@hash_function, key, @data)
    end

end

class CipherSimulator

    def initialize(data, key)
        @data = data
        @key = key
    end

    def encrypt
        [@data.bytes, @key.bytes.cycle].transpose.map { |a, b| a ^ b }.pack('C*')
    end

    def decrypt
        encrypt
    end

end

def main
    data = OpenSSL::Random.random_bytes(32)
    key = OpenSSL::Random.random_bytes(16)
    hash_sim = HashSimulator.new(data)
    hmac_sim = CipherSimulator.new(hash_sim.generate_hash.encode, key)
    encrypted_hmac = hmac_sim.encrypt
    decrypted_hmac = hmac_sim.decrypt
    puts 'Original HMAC:', hash_sim.generate_hmac(key)
    puts 'Encrypted HMAC:', [encrypted_hmac].pack('m0')
    puts 'Decrypted HMAC:', [decrypted_hmac].pack('m0')
end

main if __FILE__ == $0