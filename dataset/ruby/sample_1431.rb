require 'digest'
require 'openssl'

class HashSimulator

  def initialize(data)
    @data = data
    @hash = Digest::SHA256.hexdigest(data)
  end

  def update(new_data)
    @data += new_data
    @hash = Digest::SHA256.hexdigest(@data)
  end

  def get_hash
    @hash
  end
end

class CipherSimulator

  def initialize(key)
    @key = key
    @cipher = OpenSSL::AES.new(key, :CBC)
  end

  def encrypt(data)
    padded_data = OpenSSL::PKCS7.pad(data, @cipher.block_size)
    encrypted_data = @cipher.update(padded_data) + @cipher.final
    encrypted_data
  end

  def decrypt(encrypted_data)
    decrypted_data = @cipher.update(encrypted_data) + @cipher.final
    OpenSSL::PKCS7.unpad(decrypted_data)
  end
end

def main
  data = 'Hello, World!'
  hash_sim = HashSimulator.new(data)
  puts 'Initial Hash:', hash_sim.get_hash
  new_data = ' Additional Data'
  hash_sim.update(new_data)
  puts 'Updated Hash:', hash_sim.get_hash
  key = OpenSSL::Random.random_bytes(16)
  cipher_sim = CipherSimulator.new(key)
  encrypted = cipher_sim.encrypt(data)
  puts 'Encrypted:', encrypted
  decrypted = cipher_sim.decrypt(encrypted)
  puts 'Decrypted:', decrypted
end

main