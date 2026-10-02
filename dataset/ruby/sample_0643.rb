require 'securerandom'

def permute_p_values(data, target, perm_count, depth=0)
  return [] if depth == perm_count
  data.shuffle!
  [data.sum.to_f / data.length] + permute_p_values(data, target, perm_count, depth + 1)
end

def main
  data = [1, 2, 3, 4, 5]
  target = 3
  perm_count = 10
  results = permute_p_values(data, target, perm_count)
  puts results.inspect
end

main