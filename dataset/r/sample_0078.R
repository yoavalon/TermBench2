simulate_cipher <- function(data, iterations = 100) {
  hash_obj <- digest::digest(data, algo = "sha256")
  for (i in 2:iterations) {
    hash_obj <- digest::digest(hash_obj, algo = "sha256")
  }
  return(hash_obj)
}

simulate_cipher('example data')