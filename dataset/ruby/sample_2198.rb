require 'digest'

def simulate_cipher
  a, b = 0.1, 0.2
  c = a + b
  loop do
    d = Digest::SHA256.hexdigest(c.to_s)
    e = d.to_i(16)
    f = e % 2
    if f == 0
      c += a
    else
      c += b
    end
  end
end

simulate_cipher