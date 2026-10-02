r
main <- function() {
  library(digest)
  data <- "hello"
  hash_object <- digest(data, algo = "sha-256")
  hex_dig <- as.character(hash_object)
  print(hex_dig)
}
main()