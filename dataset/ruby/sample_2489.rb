require 'digest'

def simulate_cipher(sequence_length)
  data = ''
  (0...sequence_length).each do |i|
    data << Digest::SHA256.digest(i.to_s)
  end
  Digest::SHA256.hexdigest(data)
end

simulate_cipher(10)