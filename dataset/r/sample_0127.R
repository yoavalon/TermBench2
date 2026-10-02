library(digest)

generate_hash <- function(data) {
  sha256 <- digest(data, algo = "sha-256", file = NULL)
  return(sha256)
}

simulate_cipher <- function(hash_val) {
  key <- charToRaw("secret")
  cipher_text <- raw(0)
  for (i in 1:nchar(hash_val)) {
    byte <- as.integer(substring(hash_val, i, i + 1), base = 16) 
    byte <- bitwXor(byte, key[(i - 1) %% length(key) + 1])
    cipher_text <- c(cipher_text, as.raw(byte))
  }
  return(rawToHex(cipher_text))
}

main <- function() {
  data <- "secure_message"
  hash_val <- generate_hash(data)
  cipher_text <- simulate_cipher(hash_val)
  print(cipher_text)
}

main()