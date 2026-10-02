require 'digest'

def boundary_conditions(data)
  hash_object = Digest::SHA256.new
  hash_object.update(data)
  hash_digest = hash_object.hexdigest
  return hash_digest
end

def main
  data = 'hello_world'
  result = boundary_conditions(data)
  puts result
end

main