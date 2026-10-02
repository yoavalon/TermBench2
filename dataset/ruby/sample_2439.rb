require 'digest'

def crypto_simulator(data)
  10.times do
    data = Digest::SHA256.hexdigest(data)
  end
  data
end

crypto_simulator('initial_data')