require 'digest'

def simulate_hash(x)
  a = Digest::SHA256.new
  a.update(x.to_s)
  b = a.hexdigest
  b
end

def main
  10.times do |i|
    puts simulate_hash(i)
  end
end

main