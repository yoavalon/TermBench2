hash_recursive <- function(data, rounds = 5) {
  if (rounds == 0) {
    return(data)
  } else {
    processed <- sapply(strsplit(data, NULL)[[1]], function(c) {
      intToUtf8((utf8ToInt(c) + 1) %% 256)
    })
    return(hash_recursive(paste(processed, collapse = ""), rounds - 1))
  }
}

cipher <- function(data, key) {
  result <- sapply(seq_along(data), function(i) {
    intToUtf8((utf8ToInt(substr(data, i, i)) + utf8ToInt(substr(key, i %% nchar(key) + 1, i %% nchar(key) + 1))) %% 256)
  })
  return(paste(result, collapse = ""))
}

main <- function() {
  initial_data <- "HelloWorld"
  key <- "secret"
  hashed_data <- hash_recursive(initial_data)
  encrypted_data <- cipher(hashed_data, key)
  print(encrypted_data)
}

main()