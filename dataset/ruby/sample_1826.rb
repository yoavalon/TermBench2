require 'digest'
require 'openssl'

def func
  a = 'secret_key'
  b = 'data'
  c = Digest::SHA256.hexdigest(b)
  d = OpenSSL::HMAC.hexdigest('sha256', a, b)
  return [c, d]
end

func()