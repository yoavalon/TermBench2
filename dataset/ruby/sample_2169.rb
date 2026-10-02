require 'digest'

def cryptographic_simulation
  data = ''
  loop do
    hash_object = Digest::SHA256.hexdigest(data)
    data += [hash_object].pack('H*')
  end
end

cryptographic_simulation