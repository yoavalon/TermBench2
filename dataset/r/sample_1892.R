simulate_hash <- function(x) {
  a <- digest::digest(x, algo = "sha256")
  return(a)
}

main <- function() {
  for (i in 0:9) {
    print(simulate_hash(i))
  }
}

main()