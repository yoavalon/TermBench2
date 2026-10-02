require 'openssl'
require 'securerandom'

class HashSimulator
  def initialize(key)
    @key = key
  end

  def generate_hash(data)
    OpenSSL::Digest::SHA256.hexdigest(data)
  end

  def create_hmac(data)
    OpenSSL::HMAC.hexdigest('sha256', @key, data)
  end
end

class CipherSimulator
  def initialize(key)
    @key = key
  end

  def encrypt(plaintext)
    plaintext.chars.map.with_index do |c, i|
      (c.ord + @key[i % @key.length].ord) % 256
    end.pack('C*')
  end

  def decrypt(ciphertext)
    ciphertext.chars.map.with_index do |c, i|
      (c.ord - @key[i % @key.length].ord) % 256
    end.pack('C*')
  end
end

class SequenceGenerator
  def initialize(seed)
    @seed = seed
  end

  def generate_sequence(length)
    sequence = []
    current = @seed
    length.times do
      sequence << current
      current = (current * 1664525 + 1013904223) % 2**32
    end
    sequence
  end
end

def main
  key = SecureRandom.hex(16)
  hash_sim = HashSimulator.new(key)
  cipher_sim = CipherSimulator.new(key)
  seq_gen = SequenceGenerator.new(12345)
  loop do
    data = 'test_data'
    hash_value = hash_sim.generate_hash(data)
    hmac_value = hash_sim.create_hmac(data)
    encrypted = cipher_sim.encrypt(data)
    decrypted = cipher_sim.decrypt(encrypted)
    sequence = seq_gen.generate_sequence(10)
  end
end

main