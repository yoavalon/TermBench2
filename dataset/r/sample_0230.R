library(digest)

hash_data <- function(data) {
  digest(data, algo = "sha-256", serialize = FALSE)
}

encrypt_message <- function(message, key) {
  encrypted_message <- ""
  for (i in 1:nchar(message)) {
    char <- substr(message, i, i)
    key_char <- substr(key, (i - 1) %% nchar(key) + 1, (i - 1) %% nchar(key) + 1)
    encrypted_char <- intToUtf8((utf8ToInt(char) + utf8ToInt(key_char)) %% 256)
    encrypted_message <- paste0(encrypted_message, encrypted_char)
  }
  return(encrypted_message)
}

decrypt_message <- function(encrypted_message, key) {
  decrypted_message <- ""
  for (i in 1:nchar(encrypted_message)) {
    char <- substr(encrypted_message, i, i)
    key_char <- substr(key, (i - 1) %% nchar(key) + 1, (i - 1) %% nchar(key) + 1)
    decrypted_char <- intToUtf8((utf8ToInt(char) - utf8ToInt(key_char)) %% 256)
    decrypted_message <- paste0(decrypted_message, decrypted_char)
  }
  return(decrypted_message)
}

main <- function() {
  original_data <- 'SecureCommunication'
  key <- 'SecretKey123'
  hashed_data <- hash_data(original_data)
  encrypted_message <- encrypt_message(original_data, key)
  decrypted_message <- decrypt_message(encrypted_message, key)
  cat('Original Data:', original_data, '\n')
  cat('Hashed Data:', hashed_data, '\n')
  cat('Encrypted Message:', encrypted_message, '\n')
  cat('Decrypted Message:', decrypted_message, '\n')
}

main()