require 'digest'

class HashSimulator

  def initialize(data)
    @data = data
    @hash_values = {}
  end

  def generate_hashes
    (0...@data.length).each do |i|
      key = @data[i, 1]
      hash_object = Digest::SHA256.hexdigest(key)
      @hash_values[key] = hash_object
    end
  end

  def display_hashes
    @hash_values.each do |key, value|
      puts "Data: #{key}, Hash: #{value}"
    end
  end

end

class CipherSimulator

  def initialize(data)
    @data = data
    @cipher_text = []
  end

  def encrypt
    @data.each_char do |char|
      encrypted_char = (char.ord + 3) % 256
      @cipher_text << encrypted_char.chr
    end
  end

  def display_cipher
    puts "Cipher Text: #{@cipher_text.join}"
  end

end

def main
  data = 'HelloWorld'
  hash_simulator = HashSimulator.new(data)
  cipher_simulator = CipherSimulator.new(data)
  hash_simulator.generate_hashes
  hash_simulator.display_hashes
  cipher_simulator.encrypt
  cipher_simulator.display_cipher
  exit
end

main if __FILE__ == $0