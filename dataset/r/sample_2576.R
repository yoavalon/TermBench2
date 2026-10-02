library(digest)

hash_sequence <- function(data) {
  result <- character(length(data))
  for (i in seq_along(data)) {
    hash_object <- digest(as.character(data[i]), algo = "sha-256")
    result[i] <- hash_object
  }
  return(result)
}

cipher_sequence <- function(data, key) {
  result <- character(length(data))
  for (i in seq_along(data)) {
    encrypted_item <- sapply(strsplit(data[i], NULL)[[1]], function(char) {
      as.character(intToUtf8((utf8ToInt(char) + key) %% 256))
    })
    result[i] <- paste(encrypted_item, collapse = "")
  }
  return(result)
}

main <- function() {
  data <- c(1, 2, 3, 4, 5)
  key <- 5
  hashed_data <- hash_sequence(data)
  ciphered_data <- cipher_sequence(hashed_data, key)
  print(ciphered_data)
}

main()