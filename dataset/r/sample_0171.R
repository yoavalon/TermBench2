library(digest)

hash_data <- function(data) {
  return(digest(data, algo = "sha256", serialize = FALSE))
}

encrypt_message <- function(message) {
  key <- 'secret_key'
  encrypted <- ''
  for (i in 1:nchar(message)) {
    char <- substr(message, i, i)
    key_char <- substr(key, (i - 1) %% nchar(key) + 1, (i - 1) %% nchar(key) + 1)
    encrypted <- paste0(encrypted, intToUtf8((charToRaw(char) + charToRaw(key_char)) %% 256))
  }
  return(encrypted)
}

main <- function() {
  message <- 'Hello, World!'
  hashed <- hash_data(message)
  encrypted <- encrypt_message(hashed)
  print(encrypted)
}

main()