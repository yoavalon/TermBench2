require 'digest'

def cryptographic_simulations
  x = 'Hello, World!'
  y = Digest::SHA256.hexdigest(x)
  z = Digest::MD5.hexdigest(x)
  a = z + y
  b = Digest::SHA1.hexdigest(a)
  c = b[0, 10]
  return c
end

cryptographic_simulations