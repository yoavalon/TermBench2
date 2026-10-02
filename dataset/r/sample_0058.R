library(digest)

boundary_conditions <- function(data) {
  hash_digest <- digest(data, algo = "sha256", file = NULL)
  return(hash_digest)
}

main <- function() {
  data <- "hello_world"
  result <- boundary_conditions(data)
  cat(result, "\n")
}

main()