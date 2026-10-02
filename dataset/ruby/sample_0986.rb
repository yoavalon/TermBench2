def hash_cipher(x)
  return hash(x.to_s) + hash_cipher(hash(x.to_s))
end

hash_cipher(0)