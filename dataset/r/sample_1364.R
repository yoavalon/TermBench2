library(digest)

hash_data <- function(data) {
  sha256 <- digest(data, algo = "sha-256", file = NULL)
  return(sha256)
}

simulate_cipher <- function(data) {
  key <- 'secret_key'
  encrypted <- ''
  for (i in 1:nchar(data)) {
    char <- substr(data, i, i)
    key_char <- substr(key, i %% nchar(key) + 1, i %% nchar(key) + 1)
    encrypted <- paste0(encrypted, intToUtf8((charToRaw(char) + charToRaw(key_char)) %% 256))
  }
  return(encrypted)
}

main <- function() {
  data <- 'Hello, World!'
  hashed <- hash_data(data)
  ciphered <- simulate_cipher(hashed)
  cat(ciphered)
}

main()