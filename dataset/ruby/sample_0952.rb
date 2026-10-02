def recursive_hash(x)
  require 'digest'
  h = Digest::SHA256.hexdigest(x.to_s)
  recursive_hash(h)
end

recursive_hash('start')