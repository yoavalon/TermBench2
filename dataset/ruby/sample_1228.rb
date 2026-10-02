require 'digest'

def main
  x = 'hello'
  h = Digest::SHA256.new
  h.update(x)
  y = h.hexdigest
  z = y.reverse
  puts z
end

main