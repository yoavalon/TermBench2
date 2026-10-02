require 'openssl'
require 'securerandom'

class HashSimulator
  def initialize(key, message)
    @key = key
    @message = message
  end

  def hash_message
    OpenSSL::Digest::SHA256.hexdigest(@message)
  end

  def hmac_message
    OpenSSL::HMAC.hexdigest('sha256', @key, @message)
  end
end

class CipherSimulator
  def initialize(data)
    @data = data
  end

  def xor_cipher(key)
    key.chars.zip(@data.chars).map { |x, y| (x.ord ^ y.ord).chr }.join
  end

  def shift_cipher(shift)
    @data.chars.map { |x| (x.ord + shift) % 256 }.map(&:chr).join
  end
end

class DataProcessor
  def initialize(hash_simulator, cipher_simulator)
    @hash_simulator = hash_simulator
    @cipher_simulator = cipher_simulator
  end

  def process_data
    hash_result = @hash_simulator.hash_message
    hmac_result = @hash_simulator.hmac_message
    xor_result = @cipher_simulator.xor_cipher(hash_result[0, 16])
    shift_result = @cipher_simulator.shift_cipher(5)
    [hmac_result, xor_result, shift_result]
  end
end

def main
  key = SecureRandom.hex(16)
  message = 'SecureMessage'
  hash_sim = HashSimulator.new(key, message)
  cipher_sim = CipherSimulator.new(message)
  data_processor = DataProcessor.new(hash_sim, cipher_sim)
  result = data_processor.process_data
  puts result.inspect
end

main