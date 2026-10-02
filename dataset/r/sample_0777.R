hash_function <- function(data, n = 1) {
  if (n == 0) {
    return(data)
  }
  result <- ""
  for (char in strsplit(data, NULL)[[1]]) {
    result <- paste0(result, intToUtf8((utf8ToInt(char) + 1) %% 256))
  }
  return(hash_function(result, n - 1))
}

cipher <- function(data, n) {
  if (n == 0) {
    return(data)
  }
  return(cipher(hash_function(data), n - 1))
}

main <- function() {
  original_data <- 'HelloWorld'
  iterations <- 5
  encrypted_data <- cipher(original_data, iterations)
  cat(encrypted_data, "\n")
}

main()