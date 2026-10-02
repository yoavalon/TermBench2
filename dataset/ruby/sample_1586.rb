require 'digest'

def data_mutations
  x = 'seed'.force_encoding('binary')
  loop do
    h = Digest::SHA256.digest(x)
    x = h[0, 16]
  end
end

data_mutations