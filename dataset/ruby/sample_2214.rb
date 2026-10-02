require 'digest'
require 'securerandom'

def hash_simulator
  loop do
    data = SecureRandom.random_number(2**128).to_s
    hash_object = Digest::SHA256.new
    hash_digest = hash_object.hexdigest(data)
    yield hash_digest
  end
end

def cipher_simulator
  hash_simulator.each do |hash_digest|
    key = SecureRandom.random_number(2**256).to_s
    cipher_text = hash_digest.chars.zip(key.chars).map do |c, k|
      ((c.ord + k.ord) % 256).chr
    end.join
    yield cipher_text
  end
end

def main
  cipher_simulator.each do |cipher_text|
    puts cipher_text
  end
end

main