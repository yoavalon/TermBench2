library(digest)

hash_data <- function(data) {
  hash_object <- digest(data, algo = "sha256")
  return(hash_object)
}

mutate_data <- function(data, iterations) {
  for (i in 1:iterations) {
    data <- hash_data(data)
  }
  return(data)
}

main <- function() {
  initial_data <- 'seed'
  iterations <- 5
  result <- mutate_data(initial_data, iterations)
  print(result)
}

main()