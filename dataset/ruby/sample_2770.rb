require 'digest'

def simulate_cipher
  a = 'seed'
  while true
    a = Digest::SHA256.digest(a)
  end
end

simulate_cipher