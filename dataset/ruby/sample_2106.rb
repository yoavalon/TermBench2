require 'digest'

def hash_simulator
  while true
    data = Digest::SHA256.hexdigest(hash_simulator.to_s)
    puts data
  end
end

hash_simulator