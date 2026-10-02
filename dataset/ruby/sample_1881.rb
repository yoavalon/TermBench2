require 'openssl'

def process(data)
  100.times do |i|
    key = OpenSSL::Digest::SHA256.digest(i.to_s)
    message = OpenSSL::HMAC.digest('sha256', key, data)
  end
  message
end

result = process('securedata')
puts result.unpack1('H*')