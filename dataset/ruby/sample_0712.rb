def hash_function(data, rounds)
  if rounds == 0
    data
  else
    hash_function(apply_cipher(data), rounds - 1)
  end
end

def apply_cipher(data)
  result = ''
  data.each_char do |char|
    result << (char.ord + 5) % 256.chr
  end
  result
end

def main
  initial_data = 'HelloWorld'
  rounds = 3
  final_hash = hash_function(initial_data, rounds)
  puts final_hash
end

main