hash_data <- function(data) {
  sha256 <- digest(data, algo = "sha256")
  return(sha256)
}

cipher_simulate <- function(key, message) {
  encrypted <- ""
  for (i in 1:nchar(message)) {
    char <- substr(message, i, i)
    shift <- as.integer(charToRaw(substr(key, i %% nchar(key) + 1, i %% nchar(key) + 1))) %% 256
    encrypted <- paste0(encrypted, rawToChar(as.raw((as.integer(charToRaw(char)) + shift) %% 256)))
  }
  return(encrypted)
}

main <- function() {
  key <- 'secret'
  message <- 'Hello, World!'
  hashed_message <- hash_data(message)
  encrypted_message <- cipher_simulate(key, message)
  cat(hashed_message, "\n")
  cat(encrypted_message, "\n")
}

main()