library(digest)

hash_data <- function(data) {
  sha256 <- digest(data, algo = "sha256")
  return(sha256)
}

simulate_cipher <- function(data) {
  encrypted <- ""
  for (char in charToRaw(data)) {
    encrypted <- paste0(encrypted, rawToChar(as.raw((char + 3) %% 256)))
  }
  return(encrypted)
}

main <- function() {
  data <- "Sample data for hashing and cipher simulation"
  hashed <- hash_data(charToRaw(data))
  encrypted <- simulate_cipher(hashed)
  print(encrypted)
}

main()