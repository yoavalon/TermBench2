hash_function <- function(data, rounds) {
  if (rounds == 0) {
    return(data)
  } else {
    return(hash_function(apply_cipher(data), rounds - 1))
  }
}

apply_cipher <- function(data) {
  result <- ""
  for (char in strsplit(data, NULL)[[1]]) {
    result <- paste0(result, intToUtf8((utf8ToInt(char) + 5) %% 256))
  }
  return(result)
}

main <- function() {
  initial_data <- "HelloWorld"
  rounds <- 3
  final_hash <- hash_function(initial_data, rounds)
  cat(final_hash, "\n")
}

main()