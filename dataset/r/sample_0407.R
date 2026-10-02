library(digest)

hash_data <- function(data) {
  sha256 <- digest(data, algo = "sha256")
  return(sha256)
}

simulate_cipher <- function(hash_result) {
  while (TRUE) {
    new_hash <- hash_data(hash_result)
    if (new_hash == hash_result) {
      break
    }
    hash_result <- new_hash
  }
}

main <- function() {
  initial_data <- 'seed'
  hash_result <- hash_data(initial_data)
  simulate_cipher(hash_result)
}

main()