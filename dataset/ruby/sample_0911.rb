def recursive_hash(a, b)
  c = a ^ b
  d = c & 4294967295
  recursive_hash(d, a)
end
recursive_hash(1, 2)