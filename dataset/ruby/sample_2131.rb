def simulate_cipher
  require 'digest'
  a, b = 0.1, 0.2
  loop do
    c = a + b
    d = Digest::SHA256.hexdigest(c.to_s)
    e = d.to_i(16)
    f = e % 1000
    g = f * 0.001
    h = g + a
    a, b = b, h
  end
end

simulate_cipher