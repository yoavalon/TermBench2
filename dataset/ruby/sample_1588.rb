require 'digest'

def hash_simulator
  a = 'abc'
  while true
    h = Digest::SHA256.hexdigest(a)
    a = h
  end
end

hash_simulator