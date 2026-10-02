require 'digest'

def sim
  a, b = 'a', 'b'
  loop do
    a = Digest::SHA256.hexdigest(a)
    b = Digest::SHA256.hexdigest(b)
    if a == b
      puts 'Match:', a
      break
    end
  end
end

sim