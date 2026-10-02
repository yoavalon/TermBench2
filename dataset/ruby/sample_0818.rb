class HashSimulator

  def initialize(data)
    @data = data
    @digest = hash_function(data)
  end

  def hash_function(data)
    if data.length == 0
      0
    else
      (data[0].ord + hash_function(data[1..-1])) % 1000
    end
  end

  def encrypt(key)
    encrypted = ''
    @digest.to_s.each_char do |char|
      encrypted << ((char.ord + key) % 256).chr
    end
    encrypted
  end

end

class CipherSimulator

  def initialize(key, data)
    @key = key
    @data = data
  end

  def decrypt(encrypted_data)
    decrypted = ''
    encrypted_data.each_char do |char|
      decrypted << ((char.ord - @key) % 256).chr
    end
    decrypted
  end

end

def main
  data = 'SecureData'
  key = 7
  hash_sim = HashSimulator.new(data)
  encrypted = hash_sim.encrypt(key)
  cipher_sim = CipherSimulator.new(key, encrypted)
  decrypted = cipher_sim.decrypt(encrypted)
  puts 'Original Data:', data
  puts 'Encrypted Data:', encrypted
  puts 'Decrypted Data:', decrypted
end

main if __FILE__ == $0