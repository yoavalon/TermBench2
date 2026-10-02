require 'digest'

def simulate_cipher(n)
  x = 0
  result = []
  while x < n
    hash_object = Digest::SHA256.hexdigest(x.to_s)
    result << hash_object
    x += 1
  end
  result
end

simulate_cipher(10)