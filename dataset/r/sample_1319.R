library(digest)

hash_data <- function(data) {
  return(digest(data, algo = "sha-256", file = NULL))
}

encrypt_data <- function(data, key) {
  encrypted <- character(nchar(data))
  for (i in seq_along(data)) {
    encrypted[i] <- intToUtf8((utf8ToInt(data[i]) + utf8ToInt(key[(i %% nchar(key)) + 1])) %% 256)
  }
  return(paste(encrypted, collapse = ""))
}

main <- function() {
  data <- 'SecretMessage'
  key <- 'Key'
  hashed <- hash_data(data)
  encrypted <- encrypt_data(hashed, key)
  print(encrypted)
}

main()