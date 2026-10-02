library(digest)

simulate_cipher <- function() {
  data <- charToRaw("sample data")
  hash_obj <- digest(data, algo = "sha256")
  hash_digest <- rawToBits(hash_obj)
  cipher_text <- raw(0)
  for (i in 1:length(hash_digest)) {
    cipher_text <- c(cipher_text, as.raw(bitwXor(hash_digest[i], i - 1)))
  }
  return(cipher_text)
}

result <- simulate_cipher()
print(result)