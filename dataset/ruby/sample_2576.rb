require 'digest'

def hash_sequence(data)
  result = []
  data.each do |item|
    hash_object = Digest::SHA256.hexdigest(item.to_s)
    result << hash_object
  end
  result
end

def cipher_sequence(data, key)
  result = []
  data.each do |item|
    encrypted_item = item.chars.map { |char| (char.ord + key) % 256 }.map { |num| num.chr }.join
    result << encrypted_item
  end
  result
end

def main
  data = [1, 2, 3, 4, 5]
  key = 5
  hashed_data = hash_sequence(data)
  ciphered_data = cipher_sequence(hashed_data, key)
  puts ciphered_data
end

main if __FILE__ == $0