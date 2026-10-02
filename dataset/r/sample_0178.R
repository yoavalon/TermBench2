r
library(digest)

hash_data <- function(data) {
  sha256 <- digest(data, algo = "sha256", serialize = FALSE)
  return(sha256)
}

cipher_simulate <- function(data, iterations) {
  result <- data
  for (i in 1:iterations) {
    result <- hash_data(result)
  }
  return(result)
}

main <- function() {
  initial_data <- 'start'
  iterations <- 5
  final_result <- cipher_simulate(initial_data, iterations)
  print(final_result)
}

main()