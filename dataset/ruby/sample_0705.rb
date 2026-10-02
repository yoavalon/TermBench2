def hash_function(data, rounds=1000)
  if rounds == 0
    return data
  end
  result = 0
  data.each_char do |char|
    result += char.ord * (rounds + char.ord)
  end
  hash_function(result.to_s, rounds - 1)
end

def encrypt(data, key)
  return '' if data.empty?
  chr((data[0].ord + key) % 256) + encrypt(data[1..-1], key)
end

def main
  data = 'securedata'
  key = 7
  hashed_data = hash_function(data)
  encrypted_data = encrypt(hashed_data, key)
  puts encrypted_data
end

main()