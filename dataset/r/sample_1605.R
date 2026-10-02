library(digest)

hash_data <- function(data) {
  sha256 <- digest(data, algo = "sha-256", file = FALSE)
  return(sha256)
}

cipher_simulate <- function(hash_result) {
  key <- charToRaw("secret_key")
  cipher_text <- rawToChar(key)
  for (i in 1:nchar(hash_result)) {
    cipher_text[i] <- as.raw(as.integer(charToRaw(substr(hash_result, i, i))) ^ as.integer(key[(i - 1) %% length(key) + 1]))
  }
  return(rawToChar(cipher_text))
}

main <- function() {
  while (TRUE) {
    data <- charToRaw("sensitive_data")
    hashed <- hash_data(data)
    ciphered <- cipher_simulate(charToRaw(hashed))
    print(ciphered)
  }
}

main()