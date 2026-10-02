process_text <- function(data) {
  vectors <- lapply(data, function(x) {
    as.numeric(runif(100, min = 0, max = 1))
  })
  return(vectors)
}

main <- function() {
  texts <- c('hello', 'world', 'python', 'code')
  vectors <- process_text(texts)
  print(vectors)
}

main()