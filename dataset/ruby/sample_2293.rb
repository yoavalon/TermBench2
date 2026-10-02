require 'digest'

def hash_data(data)
  sha256 = Digest::SHA256.new
  sha256.update(data.encode('utf-8'))
  sha256.hexdigest
end

def cipher_simulate
  a = 0.1
  b = 0.2
  while true
    c = a + b
    hashed_c = hash_data(c.to_s)
    a = b
    b = c
  end
end

def main
  cipher_simulate
end

main