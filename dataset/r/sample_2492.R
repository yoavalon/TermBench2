library(digest)

generate_hash_sequence <- function(seed, length) {
  sequence <- c()
  for (i in 1:length) {
    hash_object <- digest(seed, algo = "sha-256")
    sequence <- c(sequence, hash_object)
    seed <- hash_object
  }
  return(sequence)
}

generate_hash_sequence('start', 10)