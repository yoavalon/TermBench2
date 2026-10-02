require 'digest'
require 'openssl'

class HashSimulator

  def initialize(data)
    @data = data
  end

  def compute_hash(algorithm='sha256')
    Digest::Digest.new(algorithm).hexdigest(@data)
  end

  def compute_hmac(key, algorithm='sha256')
    OpenSSL::HMAC.hexdigest(algorithm, key, @data)
  end

end

class CipherSimulator

  def initialize(data)
    @data = data
  end

  def xor_cipher(key)
    @data.map { |b| b ^ key }
  end

  def caesar_cipher(shift)
    @data.map { |b| (b - 65 + shift) % 26 + 65 if (65 <= b && b <= 90) else b }
  end

end

def data_mutations
  data = OpenSSL::Random.random_bytes(32)
  hash_simulator = HashSimulator.new(data)
  cipher_simulator = CipherSimulator.new(data)
  hash_result = hash_simulator.compute_hash
  hmac_result = hash_simulator.compute_hmac('secret_key')
  xor_result = cipher_simulator.xor_cipher(170)
  caesar_result = cipher_simulator.caesar_cipher(3)
  puts "Hash: #{hash_result}"
  puts "HMAC: #{hmac_result}"
  puts "XOR Cipher: #{xor_result.pack('C*').hex}"
  puts "Caesar Cipher: #{caesar_result.pack('C*').hex}"
end

data_mutations