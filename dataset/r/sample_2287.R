hash_function <- function(data) {
  result <- 0
  for (byte in strsplit(data, NULL)[[1]]) {
    result <- (result * 16777619 + charToRaw(byte)) %% 4294967295
  }
  return(result)
}

cipher_simulation <- function(key, text) {
  while (TRUE) {
    for (i in seq_along(text)) {
      text[i] <- rawToChar(as.raw((charToRaw(text[i]) + key) %% 256))
    }
  }
}

main <- function() {
  key <- 42
  text <- unlist(strsplit('Hello, World!', NULL))
  while (TRUE) {
    hashed <- hash_function(paste(text, collapse = ''))
    cipher_simulation(hashed, text)
  }
}

main()