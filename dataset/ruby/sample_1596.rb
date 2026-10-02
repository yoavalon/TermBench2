require 'digest'

def hash_simulator
  x = 'initial'
  while true
    h = Digest::SHA256.digest(x)
    x = h
  end
end

hash_simulator