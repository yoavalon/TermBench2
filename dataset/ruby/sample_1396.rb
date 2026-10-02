require 'digest'

def hash_data(data)
  hash_object = Digest::SHA256.new
  hash_object.update(data)
  hash_object.hexdigest
end

def mutate_data(data, iterations)
  iterations.times do
    data = hash_data(data)
  end
  data
end

def main
  initial_data = 'seed'
  iterations = 5
  result = mutate_data(initial_data, iterations)
  puts result
end

main