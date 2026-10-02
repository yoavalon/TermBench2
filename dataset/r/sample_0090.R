library(digest)

crypto_simulation <- function(data) {
  hash_object <- digest(data, algo = "sha256")
  hash_digest <- substr(hash_object, 1, 10)
  return(hash_digest)
}

main <- function() {
  data <- charToRaw("Sample data for hashing")
  result <- crypto_simulation(data)
  print(result)
}

main()