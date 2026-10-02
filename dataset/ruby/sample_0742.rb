def hash_function(data, rounds)
  if rounds == 0
    return data
  else
    result = ''
    data.each_char do |char|
      result << ((char.ord + rounds) % 256).chr
    end
    return hash_function(result, rounds - 1)
  end
end

def cipher_encrypt(data, rounds)
  if rounds == 0
    return data
  else
    encrypted = ''
    data.each_char do |char|
      encrypted << ((char.ord * rounds) % 256).chr
    end
    return cipher_encrypt(encrypted, rounds - 1)
  end
end

def main
  initial_data = 'Hello'
  hashed_data = hash_function(initial_data, 3)
  encrypted_data = cipher_encrypt(hashed_data, 2)
  puts encrypted_data
end

main