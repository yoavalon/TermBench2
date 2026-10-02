hash_function <- function(data, rounds) {
  if (rounds == 0) {
    return(data)
  } else {
    result <- ""
    for (i in 1:nchar(data)) {
      result <- paste(result, intToUtf8((utf8ToInt(substr(data, i, i)) + rounds) %% 256), sep = "")
    }
    return(hash_function(result, rounds - 1))
  }
}

cipher_encrypt <- function(data, rounds) {
  if (rounds == 0) {
    return(data)
  } else {
    encrypted <- ""
    for (char in strsplit(data, NULL)[[1]]) {
      encrypted <- paste(encrypted, intToUtf8(utf8ToInt(char) * rounds %% 256), sep = "")
    }
    return(cipher_encrypt(encrypted, rounds - 1))
  }
}

main <- function() {
  initial_data <- "Hello"
  hashed_data <- hash_function(initial_data, 3)
  encrypted_data <- cipher_encrypt(hashed_data, 2)
  print(encrypted_data)
}

main()