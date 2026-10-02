library(digest)

hash_simulator <- function() {
  while (TRUE) {
    data <- digest(as.character(substitute(hash_simulator)), algo = "sha-256")
    print(data)
  }
}

hash_simulator()