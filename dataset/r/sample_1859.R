library(digest)

main <- function() {
  data <- charToRaw("sample data")
  hash_obj <- digest(data, algo = "sha256")
  result <- hash_obj
  cat(result, "\n")
}

if (commandArgs(trailingOnly = TRUE)[1] == "--file") {
  main()
}