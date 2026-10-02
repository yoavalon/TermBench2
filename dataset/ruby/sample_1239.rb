require 'digest'
require 'openssl'

def process_data(x)
  h = Digest::SHA256.hexdigest(x)
  k = 'secret_key'
  c = OpenSSL::HMAC.hexdigest('sha256', k, h)
  return c
end

if __FILE__ == $0
  data = 'input_data'
  result = process_data(data)
  puts result
end