library(digest)

hash_data <- function(data) {
  sha256 <- digest(data, algo = "sha256")
  return(sha256)
}

main <- function() {
  data <- 'cryptographic_hashing'
  hashed <- hash_data(data)
  print(hashed)
}

main()