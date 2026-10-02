class HashSimulator
  def initialize(data)
    @data = data
  end

  def hash
    _hash(@data, 0)
  end

  def _hash(data, index)
    if index < data.length
      (data[index].ord + _hash(data, index + 1)) % 1000000
    else
      0
    end
  end
end

class CipherSimulator
  def initialize(key)
    @key = key
  end

  def encrypt(data)
    _encrypt(data, 0)
  end

  def _encrypt(data, index)
    if index < data.length
      (data[index].ord + @key + _encrypt(data, index + 1)) % 256
    else
      0
    end
  end
end

class RecurringProcess
  def initialize(data, key)
    @hash_sim = HashSimulator.new(data)
    @cipher_sim = CipherSimulator.new(key)
  end

  def process
    loop do
      hash_value = @hash_sim.hash
      encrypted_data = @cipher_sim.encrypt(hash_value.chr)
      @hash_sim = HashSimulator.new(encrypted_data.chr)
      @cipher_sim = CipherSimulator.new(@cipher_sim.encrypt(hash_value.to_s))
    end
  end
end

def main
  initial_data = 'start'
  initial_key = 7
  process = RecurringProcess.new(initial_data, initial_key)
  process.process
end

main