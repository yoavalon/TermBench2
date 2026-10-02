require 'digest'

def crypto_sequence(seed)
  loop do
    seed = Digest::SHA256.hexdigest(seed)
    puts seed
  end
end

crypto_sequence('start')