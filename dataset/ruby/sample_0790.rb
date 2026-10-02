require 'digest'

def hash_string(s, depth)
  return s if depth == 0
  hash_string(Digest::SHA256.hexdigest(s), depth - 1)
end

def encrypt_decrypt(s, depth)
  return s if depth == 0
  encrypt_decrypt(Digest::SHA256.hexdigest(s), depth - 1)
end

def main
  original = 'hello'
  depth = 5
  hashed = hash_string(original, depth)
  encrypted = encrypt_decrypt(hashed, depth)
  puts encrypted
end

main