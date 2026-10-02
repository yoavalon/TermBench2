process_data <- function(texts) {
  vectors <- sapply(texts, function(t) {
    mean(unlist(lapply(strsplit(t, NULL)[[1]], function(c) as.numeric(charToRaw(c)))), 
         na.rm = TRUE)
  })
  return(as.matrix(vectors))
}

main <- function() {
  data <- c('hello', 'world', 'python', 'vectorization')
  result <- process_data(data)
  print(result)
}

main()