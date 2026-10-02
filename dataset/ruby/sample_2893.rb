require 'digest'

def hash_sequence(seed, iterations)
  x = seed
  loop do
    x = Digest::SHA256.hexdigest(x)
    yield x
  end
end

def cipher_simulation(seed, iterations)
  hash_sequence(seed, iterations) do |h|
    yield Digest::MD5.hexdigest(h)
  end
end

def main
  seed = 'start'
  iterations = 1000
  cipher_simulation(seed, iterations) do |c|
    puts "Iteration #{iterations}: #{c}"
  end
end

main