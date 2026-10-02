require 'digest'

class HashSimulator
  def initialize(data)
    @data = data
    @hash_algorithms = ['md5', 'sha1', 'sha256', 'sha512']
  end

  def apply_hash(algorithm)
    Digest.send(algorithm).hexdigest(@data)
  end

  def simulate_hashes
    results = {}
    @hash_algorithms.each do |algo|
      results[algo] = apply_hash(algo)
    end
    results
  end
end

class CipherSimulator
  def initialize(data, key)
    @data = data
    @key = key
  end

  def xor_cipher
    encrypted = []
    @data.each_byte do |byte|
      encrypted << (byte ^ @key[byte % @key.length])
    end
    encrypted.pack('C*')
  end

  def simulate_ciphers
    {'xor' => xor_cipher}
  end
end

class DataMutator
  def initialize(data)
    @data = data.encode('utf-8')
    @key = 'secret'.b
  end

  def mutate
    hash_sim = HashSimulator.new(@data)
    cipher_sim = CipherSimulator.new(@data, @key)
    hashes = hash_sim.simulate_hashes
    ciphers = cipher_sim.simulate_ciphers
    {'hashes' => hashes, 'ciphers' => ciphers}
  end
end

def main
  data = 'Sample data for cryptographic simulation'
  mutator = DataMutator.new(data)
  result = mutator.mutate
  puts result
end

main