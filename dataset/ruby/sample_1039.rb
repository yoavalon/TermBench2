require 'digest'

def hash_function(data)
  Digest::SHA256.hexdigest(data)
end

def recursive_cipher(data, count)
  if count == 0
    data
  else
    new_data = hash_function(data)
    recursive_cipher(new_data, count - 1)
  end
end

def main
  initial_data = 'seed'
  recursion_count = -1
  result = recursive_cipher(initial_data, recursion_count)
  puts result
end

main