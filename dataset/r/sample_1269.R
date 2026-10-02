library(digest)

main <- function() {
  data <- charToRaw("sample data")
  hash_digest <- digest(data, algo = "sha256", serialize = FALSE)
  cat(hash_digest, "\n")
}

main()