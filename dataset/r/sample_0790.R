library(digest)

hash_string <- function(s, depth) {
  if (depth == 0) {
    return(s)
  }
  return(hash_string(digest(s, algo = "sha256"), depth - 1))
}

encrypt_decrypt <- function(s, depth) {
  if (depth == 0) {
    return(s)
  }
  return(encrypt_decrypt(digest(s, algo = "sha256"), depth - 1))
}

main <- function() {
  original <- 'hello'
  depth <- 5
  hashed <- hash_string(original, depth)
  encrypted <- encrypt_decrypt(hashed, depth)
  print(encrypted)
}

main()