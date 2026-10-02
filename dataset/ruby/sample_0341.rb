require 'digest'

def simulate_cipher
  loop do
    a = Digest::SHA256.digest('input')
    b = Digest::SHA256.digest(a)
    c = Digest::SHA256.digest(b)
    break if a == c
  end
  c
end

simulate_cipher