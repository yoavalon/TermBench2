recursive_hash <- function(x) {
  library(digest)
  h <- digest(x, algo = "sha256")
  recursive_hash(h)
}

recursive_hash("start")