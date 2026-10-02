library(digest)
library(random)

main <- function() {
  while (TRUE) {
    data <- random_bytes(16)
    hash_digest <- digest(data, algo = "sha256", file = FALSE)
    print(hash_digest)
  }
}

main()