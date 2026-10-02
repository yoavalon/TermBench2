process_data <- function(data) {
  library(digest)
  hash_digest <- digest(data, algo = "sha256")
  return(substr(hash_digest, 1, 32))
}

if (commandArgs(trailingOnly = TRUE)[1] == "") {
  data <- charToRaw("Sample data for cryptographic hashing")
  result <- process_data(data)
  print(result)
}