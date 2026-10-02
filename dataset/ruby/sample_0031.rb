def hash_cipher_simulation(data)
  require 'digest'
  3.times do
    data = Digest::SHA256.hexdigest(data)
  end
  data
end

if __FILE__ == $0
  result = hash_cipher_simulation('initial_data')
  puts result
end