require 'digest'

def hash_cipher(data)
  10.times do
    data = Digest::SHA256.hexdigest(data)
  end
  data
end

x = 'initial_data'
y = hash_cipher(x)
puts y