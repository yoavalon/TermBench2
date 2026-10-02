require 'digest'

def simulate_cipher(input_data, rounds)
  data = input_data.encode
  rounds.times do
    hash_object = Digest::SHA256.digest(data)
    data = hash_object
  end
  data
end

def main
  result = simulate_cipher('Hello, World!', 3)
  puts result.unpack1('H*')
end

main