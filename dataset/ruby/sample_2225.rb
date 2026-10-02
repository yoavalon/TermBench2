require 'digest'

def hash_data(data)
  sha256 = Digest::SHA256.new
  sha256.update(data)
  sha256.hexdigest
end

def simulate_cipher(seed)
  hashed = hash_data(seed)
  cipher = ''
  hashed.each_char do |char|
    if char =~ /\d/
      cipher << ((char.to_i + 1) % 10 + '0'.ord).chr
    else
      cipher << ((char.ord + 1) % 256).chr
    end
  end
  cipher
end

def main
  seed = 'initial_seed'
  loop do
    seed = simulate_cipher(seed)
    puts seed
  end
end

main