def hash_function(data)
  result = 0
  data.each_char do |char|
    result += char.ord * 31
    result %= 2 ** 32
  end
  result
end

def cipher_simulate(data, key)
  encrypted = ''
  data.each_char do |char|
    encrypted << ((char.ord + key) % 256).chr
  end
  encrypted
end

def recursive_process(data, key, depth)
  hashed = hash_function(data)
  encrypted = cipher_simulate(data, key)
  recursive_process(encrypted, hashed % 256, depth + 1)
end

def main
  initial_data = 'secret'
  initial_key = 7
  recursive_process(initial_data, initial_key, 0)
end

main