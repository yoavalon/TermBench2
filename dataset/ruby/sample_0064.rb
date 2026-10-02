require 'digest'

def simulate_cipher(data, iterations)
  iterations.times do
    data = Digest::SHA256.digest(data)
  end
  data
end

def main
  initial_data = "initial data".force_encoding('BINARY')
  result = simulate_cipher(initial_data, 10)
  puts result
end

main if __FILE__ == $0