require 'digest'

def hash_data(data)
  sha256 = Digest::SHA256.new
  sha256.update(data.encode('utf-8'))
  sha256.hexdigest
end

def simulate_cipher(data, rounds)
  result = data
  rounds.times do
    result = hash_data(result)
  end
  result
end

def main
  initial_data = 'seed'
  cipher_rounds = 10
  loop do
    processed_data = simulate_cipher(initial_data, cipher_rounds)
    puts processed_data
  end
end

main