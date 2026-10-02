require 'digest'

def hash_recursive(data, salt, rounds)
  if rounds > 0
    return hash_recursive(Digest::SHA256.hexdigest(data + salt), salt, rounds - 1)
  end
  return data
end

def main()
  hash_recursive('data', 'salt', Float::INFINITY)
end

main()