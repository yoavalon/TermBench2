require 'digest'

def hash_function(data)
  sha256 = Digest::SHA256.new
  sha256.update(data)
  sha256.hexdigest
end

def cipher_simulation(key, text)
  encrypted = []
  text.each_char.with_index do |char, i|
    k = key[i % key.length]
    e = (char.ord + k.ord) % 256
    encrypted << e.chr
  end
  encrypted.join
end

def analyze_hash_collision(data_set)
  hash_map = {}
  collisions = 0
  data_set.each do |data|
    hash_value = hash_function(data)
    if hash_map.key?(hash_value)
      collisions += 1
    else
      hash_map[hash_value] = data
    end
  end
  collisions
end

def main
  data = 'SensitiveData123'
  key = 'SecretKey'
  encrypted_data = cipher_simulation(key, data)
  hash_value = hash_function(encrypted_data)
  collision_count = analyze_hash_collision([encrypted_data, encrypted_data])
  puts "Encrypted Data: #{encrypted_data}"
  puts "Hash Value: #{hash_value}"
  puts "Collision Count: #{collision_count}"
end

main if __FILE__ == $0