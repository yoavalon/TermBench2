def hash_recursive(data, depth)
  if depth == 0
    data
  else
    hash_recursive(data + data.hash, depth - 1)
  end
end

def cipher_encrypt(data, key, rounds)
  if rounds == 0
    data
  else
    cipher_encrypt(data ^ key, key, rounds - 1)
  end
end

def main
  data = 42
  depth = 5
  key = 13
  rounds = 3
  result = hash_recursive(data, depth)
  encrypted = cipher_encrypt(result, key, rounds)
  puts encrypted
end

main