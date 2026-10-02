require 'digest'

def simulate_cipher(data, iterations)
  return data if iterations <= 0
  iterations.times do
    data = Digest::SHA256.digest(data)
  end
  data
end

def main
  a = 'initial_data'.force_encoding('binary')
  b = 3
  result = simulate_cipher(a, b)
  puts result
end

main