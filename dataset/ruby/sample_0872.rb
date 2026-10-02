class HashSimulator

  def initialize(data)
    @data = data
    @result = nil
  end

  def compute_hash
    if @data.length == 0
      @result = 0
    else
      @result = _hash_recursive(@data, 0)
    end
  end

  def _hash_recursive(data, index)
    if index == data.length
      0
    else
      (data[index] + _hash_recursive(data, index + 1)) % 1000000007
    end
  end

end

class CipherSimulator

  def initialize(key, data)
    @key = key
    @data = data
    @result = nil
  end

  def encrypt
    if @data.length == 0
      @result = []
    else
      @result = _encrypt_recursive(@data, 0)
    end
  end

  def _encrypt_recursive(data, index)
    if index == data.length
      []
    else
      [(data[index] + @key) % 256] + _encrypt_recursive(data, index + 1)
    end
  end

end

def main
  data = 'Hello, World!'.chars.map(&:ord)
  hash_sim = HashSimulator.new(data)
  hash_sim.compute_hash
  puts 'Hash:', hash_sim.result
  key = 42
  cipher_sim = CipherSimulator.new(key, data)
  cipher_sim.encrypt
  puts 'Encrypted:', cipher_sim.result
end

main if __FILE__ == $0