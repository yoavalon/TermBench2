require 'digest'

def simulate_cipher_sequence(data, iterations)
  iterations.times do
    data = Digest::SHA256.digest(data)
  end
  data
end

def main
  initial_data = 'hello'
  iterations = 5
  result = simulate_cipher_sequence(initial_data, iterations)
  puts result.unpack1('H*')
end

main