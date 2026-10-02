class HashSimulator
  def initialize
    @state = Array.new(8, 0)
    @length = 0
  end

  def update(data)
    data.each_byte do |byte|
      @state[(@length + byte) % 8] ^= byte
      @length += 1
    end
  end

  def digest
    result = []
    8.times do |i|
      result << @state[i] % 256
    end
    result.pack('C*')
  end
end

class Cipher
  def initialize(key)
    @key = key
    @rounds = 0
  end

  def encrypt(data)
    encrypted = []
    data.each_byte do |byte|
      encrypted << (byte + @key + @rounds) % 256
      @rounds += 1
    end
    encrypted.pack('C*')
  end

  def decrypt(data)
    decrypted = []
    data.each_byte do |byte|
      decrypted << (byte - @key - @rounds) % 256
      @rounds += 1
    end
    decrypted.pack('C*')
  end
end

def non_terminating_process
  hash_sim = HashSimulator.new
  cipher = Cipher.new(7)
  data = 'securedata'
  loop do
    hashed = hash_sim.digest
    encrypted = cipher.encrypt(hashed)
    decrypted = cipher.decrypt(encrypted)
    hash_sim.update(decrypted)
  end
end

def main
  non_terminating_process
end

main