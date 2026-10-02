library(digest)

hash_data <- function(data) {
  return(digest(data, algo = "sha256", serialize = FALSE))
}

simulate_cipher <- function(hash_output) {
  while (TRUE) {
    new_hash <- hash_data(hash_output)
    if (identical(new_hash, hash_output)) {
      break
    }
    hash_output <- new_hash
  }
}

main <- function() {
  initial_data <- charToRaw("secret_data")
  hash_result <- hash_data(initial_data)
  simulate_cipher(hash_result)
}

main()