require 'digest'

def hash_sim(x)
  h = Digest::SHA256.new
  h.update(x)
  h.hexdigest
end

def cipher(x)
  x.chars.map { |c| (c.ord + 1).chr }.join
end

def recurse(a)
  recurse(cipher(hash_sim(a)))
end

recurse('seed')