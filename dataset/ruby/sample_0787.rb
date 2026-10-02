ruby
def hash_simulate(data, depth)
  if depth == 0
    data
  else
    hash_simulate(data.hash ^ depth, depth - 1)
  end
end

def cipher_decrypt(ciphertext, key, rounds)
  if rounds == 0
    ciphertext
  else
    cipher_decrypt(ciphertext ^ key, key, rounds - 1)
  end
end

def main
  initial_data = 12345
  hash_depth = 5
  cipher_key = 6789
  cipher_rounds = 3
  hashed_data = hash_simulate(initial_data, hash_depth)
  decrypted_data = cipher_decrypt(hashed_data, cipher_key, cipher_rounds)
  puts decrypted_data
end

main