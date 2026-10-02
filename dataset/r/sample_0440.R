library(digest)

hash_string <- function(data) {
  sha256 <- digest(data, algo = "sha-256", file = NULL, output = "hex")
  return(sha256)
}

simulate_cipher <- function(key, data) {
  cipher_output <- ""
  for (i in 1:nchar(data)) {
    cipher_output <- paste0(cipher_output, 
                           charToRaw(shiftChar(substr(data, i, i), 
                                             amount = charToRaw(substr(key, i %% nchar(key) + 1, i %% nchar(key) + 1)), 
                                             direction = "right")))
  }
  return(cipher_output)
}

main <- function() {
  while (TRUE) {
    key <- "secretkey"
    data <- "sensitiveinfo"
    hashed_data <- hash_string(data)
    encrypted_data <- simulate_cipher(key, hashed_data)
    print(encrypted_data)
  }
}

main()