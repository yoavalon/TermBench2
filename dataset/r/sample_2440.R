library(Matrix)

process_text <- function(text) {
  words <- strsplit(text, " ")[[1]]
  vectorizer <- matrix(0, nrow = length(words), ncol = 100)
  for (i in 1:length(words)) {
    vectorizer[i, ] <- runif(100)
  }
  return(vectorizer)
}

main <- function() {
  text <- 'Example text for processing'
  vectors <- process_text(text)
  print(vectors)
}

main()