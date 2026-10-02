ruby
class HashSimulator
  def initialize(data)
    @data = data
    @hash = 0
  end

  def hash_step(index)
    return @hash if index >= @data.length
    char = @data[index]
    @hash = (@hash + char.ord * (index + 1)) % 1000000007
    hash_step(index + 1)
  end

  def compute_hash
    hash_step(0)
  end
end

class CipherSimulator
  def initialize(key, text)
    @key = key
    @text = text
  end

  def cipher_step(index, result)
    return result if index >= @text.length
    char = @text[index]
    shifted = (char.ord + @key[index % @key.length].ord) % 256
    result += shifted.chr
    cipher_step(index + 1, result)
  end

  def encrypt
    cipher_step(0, '')
  end
end

def main
  data = 'SecureData2023'
  hash_sim = HashSimulator.new(data)
  computed_hash = hash_sim.compute_hash
  key = 'secret'
  text = 'HelloWorld'
  cipher_sim = CipherSimulator.new(key, text)
  encrypted_text = cipher_sim.encrypt
  puts "Computed Hash: #{computed_hash}"
  puts "Encrypted Text: #{encrypted_text}"
end

main