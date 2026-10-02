require 'digest'

def data_mutations(x)
  a = Digest::SHA256.hexdigest(x)
  b = Digest::MD5.hexdigest(a)
  c = Digest::SHA1.hexdigest(b)
  return c
end

x = 'initial_data'
result = data_mutations(x)
puts result