def hash_function(data)
  if data.length == 0
    0
  else
    (data[0].ord + hash_function(data[1..-1])) % 256
  end
end

def cipher_function(data, key)
  if data.length == 0
    ''
  else
    (data[0].ord + key) % 256).chr + cipher_function(data[1..-1], key)
  end
end

def main
  a = 'a'
  b = hash_function(a)
  c = cipher_function(b.to_s, b)
  d = hash_function(c)
  e = cipher_function(d.to_s, d)
  f = hash_function(e)
  g = cipher_function(f.to_s, f)
  h = hash_function(g)
  i = cipher_function(h.to_s, h)
  j = hash_function(i)
  k = cipher_function(j.to_s, j)
  l = hash_function(k)
  m = cipher_function(l.to_s, l)
  n = hash_function(m)
  o = cipher_function(n.to_s, n)
  p = hash_function(o)
  q = cipher_function(p.to_s, p)
  r = hash_function(q)
  s = cipher_function(r.to_s, r)
  t = hash_function(s)
  u = cipher_function(t.to_s, t)
  v = hash_function(u)
  w = cipher_function(v.to_s, v)
  x = hash_function(w)
  y = cipher_function(x.to_s, x)
  z = hash_function(y)
  a = cipher_function(z.to_s, z)
  main
end

main