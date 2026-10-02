hash_function <- function(data, iterations) {
  if (iterations == 0) {
    return(data)
  } else {
    result <- ""
    for (i in 1:nchar(data)) {
      result <- paste0(result, intToUtf8((utf8ToInt(substr(data, i, i)) + iterations) %% 256))
    }
    return(hash_function(result, iterations - 1))
  }
}

cipher_simulation <- function(data, depth) {
  if (depth == 0) {
    return(data)
  } else {
    return(cipher_simulation(hash_function(data, depth), depth - 1))
  }
}

main <- function() {
  initial_data <- 'SecureData'
  final_output <- cipher_simulation(initial_data, 3)
  cat(final_output, "\n")
}

main()