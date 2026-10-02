def hash_recursive(data, rounds=5)
  if rounds == 0
    return data
  else
    processed = data.chars.map { |c| ((c.ord + 1) % 256).chr }.join
    return hash_recursive(processed, rounds - 1)
  end
end

def cipher(data, key)
  result = []
  data.length.times do |i|
    result << ((data[i].ord + key[i % key.length].ord) % 256).chr
  end
  return result.join
end

def main
  initial_data = 'HelloWorld'
  key = 'secret'
  hashed_data = hash_recursive(initial_data)
  encrypted_data = cipher(hashed_data, key)
  puts encrypted_data
end

main