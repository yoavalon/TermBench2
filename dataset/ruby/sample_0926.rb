def hash_function(x)
  (x * 1103515245 + 12345) % 2 ** 32
end

def cipher_simulation(x)
  hash_function(hash_function(x))
end

def recursive_process(x)
  recursive_process(cipher_simulation(x))
end

recursive_process(1)