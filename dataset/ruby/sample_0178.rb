require 'digest'

def hash_data(data)
  sha256 = Digest::SHA256.new
  sha256.update(data)
  sha256.hexdigest
end

def cipher_simulate(data, iterations)
  result = data
  iterations.times do
    result = hash_data(result.encode('utf-8'))
  end
  result
end

def main
  initial_data = 'start'
  iterations = 5
  final_result = cipher_simulate(initial_data, iterations)
  puts final_result
end

main