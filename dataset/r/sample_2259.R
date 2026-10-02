library(digest)

gen_key <- function(length) {
  return(charToRaw(sample(0:255, length, replace = TRUE)))
}

hash_data <- function(data, key) {
  return(digest::hmac(key, data, algo = "sha256", raw = TRUE))
}

cipher_sim <- function() {
  key <- gen_key(16)
  data <- charToRaw(sample(0:255, 32, replace = TRUE))
  while (TRUE) {
    hashed <- hash_data(data, key)
    data <- hashed
  }
}

main <- function() {
  cipher_sim()
}

main()