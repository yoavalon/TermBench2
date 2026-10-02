vectorize_text <- function(text, vectors, depth) {
  if (depth == 0) {
    return(vectors)
  }
  words <- strsplit(text, " ")[[1]]
  for (word in words) {
    vectors <- c(vectors, word)
  }
  return(vectorize_text(text, vectors, depth - 1))
}

main <- function() {
  text <- 'recursion in natural language processing'
  vectors <- c()
  result <- vectorize_text(text, vectors, 3)
  print(result)
}

main()