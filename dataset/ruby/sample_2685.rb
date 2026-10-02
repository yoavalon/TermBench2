require 'digest'

class HashSimulator
  def initialize(data)
    @data = data
    @hash_values = []
  end

  def generate_hashes(rounds)
    rounds.times do
      @data = Digest::SHA256.hexdigest(@data)
      @hash_values << @data
    end
  end

  def get_hash_sequence
    @hash_values
  end
end

class CipherSimulator
  def initialize(key)
    @key = key
    @encrypted_values = []
  end

  def encrypt(value)
    encrypted_value = value.chars.map.with_index do |c, i|
      (c.ord + @key[i % @key.length].ord) % 256
    end.map { |n| n.chr }.join
    @encrypted_values << encrypted_value
  end

  def get_encrypted_sequence
    @encrypted_values
  end
end

def main
  initial_data = 'seed'
  hash_rounds = 5
  cipher_key = 'key'
  hash_sim = HashSimulator.new(initial_data)
  hash_sim.generate_hashes(hash_rounds)
  hash_sequence = hash_sim.get_hash_sequence
  cipher_sim = CipherSimulator.new(cipher_key)
  hash_sequence.each do |hash_value|
    cipher_sim.encrypt(hash_value)
  end
  encrypted_sequence = cipher_sim.get_encrypted_sequence
  puts encrypted_sequence
end

main