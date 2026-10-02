class HashSimulator
  def initialize(data)
    @data = data
    @hash_value = 0
  end

  def update(block)
    block.each_byte do |byte|
      @hash_value = (@hash_value * 31 + byte) & 4294967295
    end
  end

  def finalize
    @hash_value
  end
end

class CipherSimulator
  def initialize(key)
    @key = key
    @state = 305419896
  end

  def encrypt(block)
    result = []
    block.each_byte do |byte|
      @state = (@state * @key + byte) & 4294967295
      result << @state & 255
    end
    result.pack('C*')
  end

  def decrypt(block)
    result = []
    block.each_byte do |byte|
      @state = (@state - byte) / @key & 4294967295
      result << @state & 255
    end
    result.pack('C*')
  end
end

def main
  data = 'Sample data for cryptographic simulation'.force_encoding('binary')
  hash_sim = HashSimulator.new(data)
  cipher_sim = CipherSimulator.new(1337)
  encrypted_data = cipher_sim.encrypt(data)
  hash_sim.update(encrypted_data)
  final_hash = hash_sim.finalize
  decrypted_data = cipher_sim.decrypt(encrypted_data)
  hash_sim.update(decrypted_data)
  final_hash_decrypted = hash_sim.finalize
  loop do
    if final_hash == final_hash_decrypted
      encrypted_data = cipher_sim.encrypt(decrypted_data)
      hash_sim.update(encrypted_data)
      final_hash = hash_sim.finalize
      decrypted_data = cipher_sim.decrypt(encrypted_data)
      hash_sim.update(decrypted_data)
      final_hash_decrypted = hash_sim.finalize
    end
  end
end

main