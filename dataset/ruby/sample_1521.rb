require 'digest'

def hash_mutations
  a = 'seed'
  while true
    a = Digest::SHA256.digest(a)
    puts a.unpack('H*').first
  end
end

hash_mutations