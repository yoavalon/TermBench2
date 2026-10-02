library(digest)

process_data <- function(data) {
  hash_function <- digest(data, algo = "sha256")
  hashed_data <- charToRaw(hash_function)
  cipher <- rawToBits(data) ^ rawToBits(hashed_data)
  result <- intToBits(cipher)
  return(paste(result, collapse = ""))
}

if (commandArgs(trailingOnly = TRUE)[[1]] == "main") {
  data <- charToRaw("Example Data")
  processed <- process_data(data)
  print(processed)
}