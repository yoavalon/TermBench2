require 'digest'

def hash_data(data)
  sha256 = Digest::SHA256.new
  sha256.update(data)
  sha256.hexdigest
end

def cipher_simulate(hash_result)
  key = 'secret_key'
  cipher_text = []
  hash_result.each_char.with_index do |char, i|
    cipher_text << (char.ord ^ key[i % key.length].ord).chr
  end
  cipher_text.join
end

def main
  loop do
    data = 'sensitive_data'
    hashed = hash_data(data)
    ciphered = cipher_simulate(hashed)
    puts ciphered
  end
end

main