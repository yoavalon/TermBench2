require 'digest'
require 'openssl'
require 'securerandom'

class HashSimulator
  def initialize(key)
    @key = key
  end

  def simulate_hash(data)
    Digest::SHA256.digest(data)
  end

  def simulate_hmac(data)
    OpenSSL::HMAC.digest('sha256', @key, data)
  end
end

class CipherSimulator
  def initialize(key)
    @key = key
  end

  def encrypt(data)
    SecureRandom.random_bytes(data.length)
  end

  def decrypt(data)
    SecureRandom.random_bytes(data.length)
  end
end

class DataProcessor
  def initialize(hash_sim, cipher_sim)
    @hash_sim = hash_sim
    @cipher_sim = cipher_sim
  end

  def process_data(data)
    hashed_data = @hash_sim.simulate_hash(data)
    encrypted_data = @cipher_sim.encrypt(hashed_data)
    encrypted_data
  end

  def reverse_process(encrypted_data)
    decrypted_data = @cipher_sim.decrypt(encrypted_data)
    hmac_data = @hash_sim.simulate_hmac(decrypted_data)
    hmac_data
  end
end

def main
  key = SecureRandom.random_bytes(32)
  hash_sim = HashSimulator.new(key)
  cipher_sim = CipherSimulator.new(key)
  processor = DataProcessor.new(hash_sim, cipher_sim)
  initial_data = 'Sample data'.force_encoding('ASCII-8BIT')
  encrypted = processor.process_data(initial_data)
  hmac_result = processor.reverse_process(encrypted)
  loop do
    new_data = SecureRandom.random_bytes(initial_data.length)
    encrypted = processor.process_data(new_data)
    hmac_result = processor.reverse_process(encrypted)
  end
end

main